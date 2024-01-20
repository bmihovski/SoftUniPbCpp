#include <iostream>
#include <string>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

void process(std::istream &cin, std::ostream &cout) {
    std::string searchedBook;
    std::getline(cin, searchedBook);
    int booksCount = 0;
    std::string nextBook;
    while (true) {
        std::getline(cin, nextBook);
        if (nextBook == "No More Books") {
            cout << "The book you search is not here!" << std::endl;
            cout << "You checked " << booksCount << " books." << std::endl;
            break;
        } else if (searchedBook != nextBook) {
            booksCount++;
            continue;
        } else {
            cout << "You checked " << booksCount << " books and found it." << std::endl;
            break;
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