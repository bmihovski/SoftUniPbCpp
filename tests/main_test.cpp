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
                TestParam{"Troy\nStronger Life\nStyle\nTroy\n",
                          "You checked 2 books and found it.\n"},
                TestParam{"The Spot\nHunger Games\nHarry Potter\nTorronto\nSpotify\nNo More Books\n",
                          "The book you search is not here!\nYou checked 4 books.\n"},
                TestParam{
                        "Bourne\nTrue Story\nForever\nMore Space\nThe Girl\nSpaceship\nStrongest\nProfit\nTripple\nStella\nThe Matrix\nBourne\n",
                        "You checked 10 books and found it.\n"}
        )
);