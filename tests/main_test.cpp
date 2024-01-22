#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "main.cpp"

static const char *const testScenarioSeparator = "===";
struct TestParam {
    int testCaseNumber;
    std::string input;
    std::string expectedOutput;
};

class PbTest : public ::testing::TestWithParam<TestParam> {
};

std::vector<TestParam> generateTestParams() {
    std::vector<TestParam> params;
    std::ifstream inputFile("../tests/testInputs.txt");
    std::ifstream expectedOutputFile("../tests/testExpectedResults.txt");
    std::string line;
    int testCaseNumber = 0;
    std::string input;
    std::string expectedOutput;
    while (std::getline(inputFile, line)) {
        if (line == testScenarioSeparator) {
            std::string outputLine;
            while (std::getline(expectedOutputFile, outputLine) && outputLine != testScenarioSeparator) {
                expectedOutput += outputLine + "\n";
            }
            params.push_back(TestParam{testCaseNumber++, input, expectedOutput});
            input.clear();
            expectedOutput.clear();
        } else {
            input += line + "\n";
        }
    }
    if (!input.empty()) {
        std::string outputLine;
        while (std::getline(expectedOutputFile, outputLine) && outputLine != testScenarioSeparator) {
            expectedOutput += outputLine + "\n";
        }
        params.push_back(TestParam{testCaseNumber, input, expectedOutput});
    }
    return params;
}

TEST_P(PbTest, Test) {
    TestParam param = GetParam();
    std::istringstream iss(param.input);
    std::ostringstream ossOutput;
    process(iss, ossOutput);
    EXPECT_EQ(ossOutput.str(), param.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
        PbTest,
        PbTest,
        ::testing::ValuesIn(generateTestParams())
);
