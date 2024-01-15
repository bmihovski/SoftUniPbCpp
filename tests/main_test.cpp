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
                TestParam{"5 1400 F SF W W SF", "Final points: 8040\nAverage points: 1328\n40.00%\n"},
                TestParam{"4 750 SF W SF W", "Final points: 6190\nAverage points: 1360\n50.00%\n"},
                TestParam{"7 1200 SF F W F W SF W", "Final points: 11040\nAverage points: 1405\n42.86%\n"}
        )
);