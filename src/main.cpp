#include <iostream>
#include <iomanip>
#include <string>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

void process(std::istream &in, std::ostream &out) {
    int tournamentsCount;
    int startingPoints;
    int totalPoints = 0;
    int wonTournaments = 0;
    in >> tournamentsCount >> startingPoints;
    totalPoints += startingPoints;

    for (int tournamentNumber = 1; tournamentNumber <= tournamentsCount; tournamentNumber++) {
        std::string variant;
        in >> variant;
        if (variant == "W") {
            totalPoints += 2000;
            wonTournaments++;
            continue;
        } else if (variant == "F") {
            totalPoints += 1200;
            continue;
        } else {
            totalPoints += 720;
        }
    }
    out << "Final points: " << totalPoints << std::endl;
    out << "Average points: " << (totalPoints - startingPoints) / tournamentsCount << std::endl;
    out << std::fixed << std::setprecision(2) << (1.0 * wonTournaments / tournamentsCount) * 100 << "%"
        << std::endl;
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