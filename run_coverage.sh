#!/bin/sh
set -e

echo "Building with coverage enabled..."
cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build

echo "Running tests..."
cd build && ctest --output-on-failure

echo "Generating coverage report..."

# Generate coverage data (ignore unsupported GCC/gcov warnings)
lcov --ignore-errors unsupported -c -d . -o coverage.info

# Generate HTML report without trying to exclude system headers
genhtml coverage.info -o coverage_report

echo ""
echo "✓ Coverage report generated successfully!"
echo ""
echo "Summary:"
lcov --list coverage.info | tail -4
echo ""
echo "View the report at: build/coverage_report/index.html"

# Use platform-appropriate open command
if command -v open >/dev/null 2>&1; then
    open coverage_report/index.html
elif command -v xdg-open >/dev/null 2>&1; then
    xdg-open coverage_report/index.html
else
    echo "Please open build/coverage_report/index.html manually"
fi
