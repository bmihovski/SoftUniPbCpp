#!/bin/bash

bazel run @hedron_compile_commands//:refresh_all
bazel build //:main

awk '/===/{n++;next}{print >"tests/Test.in.split."n}' tests/Test.in.txt
awk '/===/{n++;next}{print >"tests/Test.out.split."n}' tests/Test.out.txt
INPUTS=(tests/Test.in.split.*)
OUTPUTS=(tests/Test.out.split.*)
for i in "${!INPUTS[@]}"; do
  echo "Running test $((i + 1))..."
  ./bazel-bin/main <"${INPUTS[i]}" >tests/temp.out.txt
  if diff -Z -B -q tests/temp.out.txt "${OUTPUTS[i]}" >/dev/null; then
    echo "Test $((i + 1)) passed!"
  else
    echo "Test $((i + 1)) failed!"
    echo "Input was:"
    cat "${INPUTS[i]}"
    echo "Output diff:"
    diff -Z -B tests/temp.out.txt "${OUTPUTS[i]}"
  fi
done
rm tests/temp.out.txt tests/Test.in.split.* tests/Test.out.split.*
