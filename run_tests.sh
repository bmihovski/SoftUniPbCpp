#!/bin/bash
num_tests=$1
for i in $(seq 1 "$num_tests"); do
  echo "Running test $i..."
  ./build/PB <Tests/Test."$i".in.txt >Tests/temp."$i".out.txt
  if diff -q Tests/temp."$i".out.txt Tests/Test."$i".out.txt >/dev/null; then
    echo "Test $i passed!"
  else
    echo "Test $i failed!"
  fi
  rm Tests/temp."$i".out.txt
done
