#!/bin/zsh

setopt KSH_ARRAYS
setopt nullglob


# Check if test files exist first
if [[ ! -f tests/Test.in.txt || ! -f tests/Test.out.txt ]]; then
  echo "Error: Test files (Test.in.txt or Test.out.txt) not found."
  exit 1
fi

cd out/Debug || exit
cmake .
make
cd ../../

# Split test files (initialize n=1 to avoid empty file)
awk 'BEGIN{n=1} /===/{n++;next} {print > ("tests/Test.in.split."n)}' tests/Test.in.txt
awk 'BEGIN{n=1} /===/{n++;next} {print > ("tests/Test.out.split."n)}' tests/Test.out.txt

# Only include files with numbers in their names
INPUTS=(tests/Test.in.split.<->(n))
OUTPUTS=(tests/Test.out.split.<->(n))

# Check if test files were created
if [[ ${#INPUTS[@]} -eq 0 || ${#OUTPUTS[@]} -eq 0 ]]; then
  echo "Error: No test files found after splitting. Check if Test.in.txt and Test.out.txt exist and contain '===' separators."
  exit 1
fi

# Debug output
# echo "Found ${#INPUTS[@]} input files: ${INPUTS[@]}"
# echo "Found ${#OUTPUTS[@]} output files: ${OUTPUTS[@]}"

# Run tests using array indices
for ((i = 0; i < ${#INPUTS[@]}; i++)); do
  test_num=$((i + 1))
  echo "Running test $test_num..."

  # Check if files exist before using them
  if [[ ! -f "${INPUTS[i]}" || ! -f "${OUTPUTS[i]}" ]]; then
    echo "Test $test_num failed! Missing files: ${INPUTS[i]} or ${OUTPUTS[i]}"
    continue
  fi

  ./out/Debug/PB <"${INPUTS[i]}" >tests/temp.out.txt 2>&1
  if diff -bB -q tests/temp.out.txt "${OUTPUTS[i]}" >/dev/null; then
    echo "Test $test_num passed!"
  else
    echo "Test $test_num failed!"
    echo "Input was:"
    cat "${INPUTS[i]}"
    echo "Expected output:"
    cat "${OUTPUTS[i]}"
    echo "Actual output:"
    if [[ -s tests/temp.out.txt ]]; then
     cat tests/temp.out.txt
    else
     echo "(No output - program may have crashed or produced no output)"
    fi
    echo ""
    echo "Output diff:"
    diff -bB tests/temp.out.txt "${OUTPUTS[i]}"
  fi
done

# Cleanup
rm -f tests/temp.out.txt tests/Test.in.split.* tests/Test.out.split.*
