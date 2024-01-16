#include <iostream>
#include <iomanip>
#include <string>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

void process(std::istream &cin, std::ostream &cout) {
    std::string username;
    std::string password;
    cin >> username >> password;
    while (true) {
        std::string passwordToCheck;
        cin >> passwordToCheck;
        if (passwordToCheck == password) {
            cout << "Welcome " << username << "!" << std::endl;
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