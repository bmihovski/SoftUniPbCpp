#include <iostream>
#include <climits>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
    std::string destination;
    double ticketPrice = 0;
    cin >> destination;
    while (destination != "End") {
        cin >> ticketPrice;
        double collectedMoney = 0;
        while (collectedMoney < ticketPrice) {
            double earnedMoney;
            cin >> earnedMoney;
            collectedMoney += earnedMoney;
        }
        if (collectedMoney >= ticketPrice) {
            cout << "Going to " << destination << "!" << std::endl;
        }
        cin >> destination;
    }
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