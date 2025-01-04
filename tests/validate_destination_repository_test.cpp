#include <gtest/gtest.h>
#include <memory>
#include "src/entities/destination/Lake.h"
#include "src/entities/repositories/DestinationRepository.h"

TEST(ValidateDestinationRepositoryTest, ValidateDestinationRepository)
{
    DestinationRepository destinationRepository;
    Lake                  lake("Great Lake");
    destinationRepository.add(std::make_unique<Lake>(lake));
    ASSERT_EQ(destinationRepository.getCollection().size(), 1);
    auto result = destinationRepository.byName("Great Lake");
    ASSERT_EQ(result.has_value(), true);
    ASSERT_EQ(result.value()->getName(), "Great Lake");
    destinationRepository.remove(lake);
    ASSERT_EQ(destinationRepository.getCollection().size(), 0);
}
