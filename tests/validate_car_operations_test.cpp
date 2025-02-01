#include <gtest/gtest.h>
#include <memory>
#include <stdexcept>
#include "src/entities/car/BaseCar.h"
#include "src/entities/car/Dacia.h"
#include "src/entities/car/VW.h"
#include "src/entities/car/Tesla.h"

struct ValidateCarTemplate
{
    std::unique_ptr<BaseCar> car;
    int                      battery_capacity;
};

class ValidateCarOperations : public ::testing::TestWithParam<ValidateCarTemplate>
{
};

TEST(ValidateCarOperations, GivenNewCarInitialMileageIsZero)
{
    const Tesla car("Model S");
    EXPECT_EQ(car.GetMileage(), 0);
}

TEST(ValidateCarOperations, GivenEmptyModelThenExeptionMessage)
{
    try
    {
        Tesla("");
    }
    catch (const std::invalid_argument& e)
    {
        EXPECT_STREQ(e.what(), "Car model cannot be null or empty.");
    }
}

TEST_P(ValidateCarOperations, GivenNewCarInitialBatteryCapacityIsSet)
{
    const ValidateCarTemplate& param = GetParam();
    EXPECT_EQ(param.car->GetBatteryCapacity(), param.battery_capacity);
}

INSTANTIATE_TEST_SUITE_P(CarBateriesTests,
                         ValidateCarOperations,
                         ::testing::Values(ValidateCarTemplate{std::make_unique<Tesla>("Model S"), 100},
                                           ValidateCarTemplate{std::make_unique<Dacia>("Model 3"), 200},
                                           ValidateCarTemplate{std::make_unique<VW>("Model X"), 300}));

TEST_P(ValidateCarOperations, GivenDriveCarThenMileageIncreaseAndBatteryDecrease)
{
    const ValidateCarTemplate& param = GetParam();
    param.car->Drive();
    EXPECT_EQ(param.car->GetMileage(), 25);
    EXPECT_EQ(param.car->GetBatteryCapacity(), param.battery_capacity - 15);
}
