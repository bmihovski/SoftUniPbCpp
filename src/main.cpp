#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  int rowsNums;
  int colsNums;
  cin >> rowsNums >> colsNums;
  int **matrix = new int *[rowsNums];
  for (int start = 0; start < rowsNums; ++start) {
    matrix[start] = new int[colsNums];
    std::string line;
    std::getline(cin >> std::ws, line);
    std::istringstream ss(line);
    for (int innerStart = 0; innerStart < colsNums; ++innerStart) {
      ss >> matrix[start][innerStart];
    }
  }
  for (int i = 0; i < colsNums; ++i) {
    int colSum = 0;
    for (int j = 0; j < rowsNums; ++j) {
      colSum += matrix[j][i];
    }
    cout << colSum << std::endl;
  }
  for (int i = 0; i < rowsNums; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;
}

int main(int argc, char **argv) {
#ifdef TESTING
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#else
  process(std::cin, std::cout);
  return 0;
#endif
}
