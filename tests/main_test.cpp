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
                TestParam{"3\nMoney\n6\nStory\n4\nSpring Time\n5\nBus\n6\nEnough\n",
                          "Average score: 5.25\nNumber of problems: 4\nLast problem: Bus\n"},
                TestParam{"2\nIncome\n3\nGame Info\n6\nBest Player\n4\n",
                          "You need a break, 2 poor grades.\n"}
        )
);