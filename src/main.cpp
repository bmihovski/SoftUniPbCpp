#include <iostream>
#include <climits>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

const std::vector<std::string> singleDigits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const std::vector<std::string> tensNumber = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty",
                                             "ninety"};
const std::vector<std::string> toNineteen = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                                             "seventeen",
                                             "eighteen", "nineteen"};

char getSeparator() {
    return ' ';
}

int process(std::istream &cin, std::ostream &cout) {
    int number;
    cin >> number;
    if (number == 0) {
        cout << "zero" << std::endl;
        return 0;
    }
    int thousands = number / 1000 % 10;
    int hundreds = number / 100 % 10;
    int tens = number / 10 % 10;
    int singles = number / 1 % 10;
    if (thousands != 0) {
        cout << singleDigits[thousands - 1];
        cout << getSeparator();
        cout << "thousand";
        cout << getSeparator();
    }
    if (hundreds != 0) {
        cout << singleDigits[hundreds - 1];
        cout << getSeparator();
        cout << "hundred";
        cout << getSeparator();
    }
    if (tens == 1) {
        cout << toNineteen[singles - 1];
        return 0;
    } else if (tens != 0) {
        cout << tensNumber[tens - 1];
        cout << getSeparator();
    }

    if (singles != 0) {
        cout << singleDigits[singles - 1];
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