#include <algorithm>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <ostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#ifdef TESTING
#include <gtest/gtest.h>
#endif

char compareStrings(const std::string &firstVectorElem,
                    const std::string &secondVectorElem) {
  char compareResult = ' ';
  bool isFirstLongerThanSecond =
      firstVectorElem.length() > secondVectorElem.length();
  bool areElemsSizeEqual =
      firstVectorElem.length() == secondVectorElem.length();
  bool isFirstBiggerThanSecond = firstVectorElem > secondVectorElem;
  bool areElemsEqual = firstVectorElem == secondVectorElem;
  if (isFirstBiggerThanSecond && areElemsSizeEqual && !areElemsEqual) {
    compareResult = '<';
  } else if (!isFirstBiggerThanSecond && areElemsSizeEqual && !areElemsEqual) {
    compareResult = '>';
  } else if (areElemsEqual && areElemsSizeEqual) {
    compareResult = '=';
  } else if (isFirstLongerThanSecond && !areElemsSizeEqual) {
    compareResult = '<';
  } else {
    compareResult = '>';
  }
  return compareResult;
}

std::vector<std::string> stringToVector(std::istream &cin) {
  std::string userInput;
  std::getline(cin >> std::ws, userInput);
  std::istringstream iss(userInput);
  std::vector<std::string> result;
  std::string word;
  while (iss >> word) {
    result.push_back(word);
  }

  return result;
}

int process(std::istream &cin, std::ostream &cout) {
  std::vector<std::string> firstVectorList = stringToVector(cin);
  std::vector<std::string> secondVectorList = stringToVector(cin);

  auto itFirst = firstVectorList.cbegin();
  auto itSecond = secondVectorList.cbegin();
  while (itFirst != firstVectorList.cend() &&
         itSecond != secondVectorList.cend()) {
    cout << compareStrings(*itFirst, *itSecond);
    ++itFirst;
    ++itSecond;
  }

  if (itFirst != firstVectorList.cend()) {
    while (itFirst != firstVectorList.cend()) {
      cout << '+';
      ++itFirst;
    }
  }

  if (itSecond != secondVectorList.cend()) {
    while (itSecond != secondVectorList.cend()) {
    }
    cout << '-';
    ++itSecond;
  }
  cout << std::endl;

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
