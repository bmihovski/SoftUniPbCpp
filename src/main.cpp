#include <iostream>
#include <iomanip>
#include <string>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

void process(std::istream &cin, std::ostream &cout) {
    while (true) {
        std::string textToPrint;
        cin >> textToPrint;
        if (textToPrint == "Stop") {
            break;
        } else {
            cout << textToPrint << std::endl;
        }
    }
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