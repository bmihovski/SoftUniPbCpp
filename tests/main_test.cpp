#include <gtest/gtest.h>
#include <sstream>
#include "main.cpp"

struct TestParam {
    std::string input;
    std::string expectedOutput;
};

class PbTest : public ::testing::TestWithParam<TestParam> {
};

TEST_P(PbTest, Test) {
    TestParam param = GetParam();

    // Prepare input and output streams
    std::istringstream input(param.input);
    std::ostringstream output;

    // Call main function
    process(input, output);

    // Check output
    EXPECT_EQ(output.str(), param.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
        PbTests,
        PbTest,
        ::testing::Values(
                TestParam{"Nakov SoftUni Sofia Bulgaria SomeText Stop AfterStop Europe HelloWorld",
                          "Nakov\nSoftUni\nSofia\nBulgaria\nSomeText\n"},
                TestParam{"Sofia Berlin Moscow Athens Madrid London Paris Stop AfterStop",
                          "Sofia\nBerlin\nMoscow\nAthens\nMadrid\nLondon\nParis\n"}
        )
);