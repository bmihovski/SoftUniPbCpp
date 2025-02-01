#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <memory>
#include <string>
#include "src/entities/destination/BaseDestination.h"
#include "src/entities/destination/Destination.h"
#include "src/entities/destination/Lake.h"
#include "src/entities/repositories/DestinationRepository.h"


struct TestDestinationParams
{
    std::string name;
    int         distance;
    std::string expected_error;
};

class ValidateDestinationRepositoryTest : public ::testing::TestWithParam<TestDestinationParams>
{
protected:
    void SetUp() override
    {
        lake_ = std::make_unique<Lake>("Great Lake");
        destination_repository_.Add(std::make_unique<Lake>(*lake_));
    }
    DestinationRepository destination_repository_;
    std::unique_ptr<Lake> lake_;
};

TEST_F(ValidateDestinationRepositoryTest, ValidateDestinationRepository)
{
    ASSERT_THAT(destination_repository_.GetCollection(), testing::SizeIs(1));
    auto result = destination_repository_.ByName("Great Lake");

    ASSERT_THAT(result, testing::Optional(testing::Pointee(testing::Property(&Destination::GetName, testing::StrEq("Great Lake")))));
    destination_repository_.Remove(*result.value());
    ASSERT_THAT(destination_repository_.GetCollection(), testing::SizeIs(0));
}

TEST_P(ValidateDestinationRepositoryTest, GivenNegativeDistanceThenException)
{
    class TestDestination : public BaseDestination
    {
    public:
        TestDestination(const std::string& name, const int distance) : BaseDestination(name, distance) {}
    };

    const auto& params = GetParam();

    EXPECT_THROW(
        try { TestDestination(params.name, params.distance); } catch (const std::invalid_argument& e) {
            EXPECT_THAT(e.what(), ::testing ::StrEq(params.expected_error));
            throw;
        },
        std::invalid_argument);
}
INSTANTIATE_TEST_SUITE_P(InvalidDestinationParams,
                         ValidateDestinationRepositoryTest,
                         testing::Values(TestDestinationParams{"Great Lake", -1, "Distance cannot be a negative number!"},
                                         TestDestinationParams{std::string(), 1, "Destination name cannot be null or empty."},
                                         TestDestinationParams{"", 1, "Destination name cannot be null or empty."}));
