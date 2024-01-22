#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "main.cpp"

static const char *const testScenarioSeparator = "===";
struct TestParam {
    int testCaseNumber;
};

class PbTest : public ::testing::TestWithParam<TestParam> {
};

std::vector<TestParam> generateTestParams() {
    std::vector<TestParam> params;
    std::ifstream inputFile("../tests/testInputs.txt");
    std::ifstream expectedOutputFile("../tests/testExpectedResults.txt");
    std::string line;
    int testCaseNumber = 0;
    while (std::getline(inputFile, line)) {
        if (line == testScenarioSeparator) {
            params.push_back(TestParam{testCaseNumber++});
        }
    }
    int expectedTestCaseNumber = 0;
    while (std::getline(expectedOutputFile, line)) {
        if (line == testScenarioSeparator) {
            expectedTestCaseNumber++;
        }
    }
    if (expectedTestCaseNumber < testCaseNumber) {
        params.resize(expectedTestCaseNumber);
    }
    return params;
}

void skipUntilScenarioSeparator(std::ifstream &file) {
    std::string line;
    while (std::getline(file, line) && line != testScenarioSeparator) {
        // Skip lines until the next test scenario
    }
}

TEST_P(PbTest, Test) {
    TestParam param = GetParam();

    // Prepare input and output streams
    std::ifstream inputFile("../tests/testInputs.txt");
    std::ifstream expectedOutputFile("../tests/testExpectedResults.txt");
    std::ostringstream oss;
    std::string line;

    // Skip previous test cases
    for (int i = 0; i < param.testCaseNumber; ++i) {
        skipUntilScenarioSeparator(inputFile);
        skipUntilScenarioSeparator(expectedOutputFile);
    }

    // Read the test input and call the main function
    while (std::getline(inputFile, line) && line != testScenarioSeparator) {
        oss << line << "\n";
    }
    std::istringstream iss(oss.str());
    std::ostringstream ossOutput;
    process(iss, ossOutput);

    std::string expectedOutput;
    while (std::getline(expectedOutputFile, line) && line != testScenarioSeparator) {
        expectedOutput += line + "\n";
    }

    EXPECT_EQ(ossOutput.str(), expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
        PbTest,
        PbTest,
        ::testing::ValuesIn(generateTestParams())
);
