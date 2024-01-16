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
                TestParam{"Nakov 1234 pass 1324 1234",
                          "Welcome Nakov!\n"},
                TestParam{"Gosho secret secret",
                          "Welcome Gosho!\n"}
        )
);