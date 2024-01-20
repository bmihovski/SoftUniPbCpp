#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
    const int failedTaskThreshold = 4;
    std::string maxFailuresStr;
    std::getline(cin, maxFailuresStr);
    int maxFailures = std::stoi(maxFailuresStr);
    std::string taskName;
    int totalScore = 0;
    int numberOfProblems = 0;
    int numberOfFailedProblems = 0;
    std::string lastProblem;
    while (true) {
        std::string taskScore;
        std::getline(cin, taskName);
        std::getline(cin, taskScore);
        if (taskName == "Enough") {
            break;
        }
        int convertedTaskScore = std::stoi(taskScore);
        numberOfProblems++;
        totalScore += convertedTaskScore;
        lastProblem = taskName;
        if (convertedTaskScore <= failedTaskThreshold) {
            numberOfFailedProblems++;
        }
        if (numberOfFailedProblems == maxFailures) {
            cout << "You need a break, " << maxFailures << " poor grades." << std::endl;
            return 0;
        }
    }
    cout << std::fixed << std::setprecision(2) << "Average score: " << (1.0 * totalScore) / numberOfProblems
         << std::endl;
    cout << "Number of problems: " << numberOfProblems << std::endl;
    cout << "Last problem: " << lastProblem << std::endl;
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