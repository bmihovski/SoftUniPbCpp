#!/bin/bash
num_tests=$1
cd out/Debug || exit
cmake .
make
cd ../../
for i in $(seq 1 "$num_tests"); do
  echo "Running test $i..."
  # Split the file content based on the separator line
  csplit -f "tests/temp." tests/Test."$i".txt '/---/'1 '{*}' >/dev/null
  ./out/Debug/PB <tests/temp.00 >tests/temp.out.txt
  if diff -q tests/temp.out.txt tests/temp.01 >/dev/null; then
    echo "Test $i passed!"
  else
    echo "Test $i failed!"
    echo "Input was:"
    cat tests/temp.00
  fi
  rm tests/temp.00 tests/temp.01 tests/temp.out.txt
done
