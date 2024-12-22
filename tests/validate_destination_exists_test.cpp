#include <gtest/gtest.h>

#include <filesystem>
#include <memory>
#include <string>
#include <vector>
#include "tools/cpp/runfiles/runfiles.h"


bool fileExists(const std::string& path)
{
    return std::filesystem::exists(path);
}

TEST(ValidateDestinationExistsTest, ValidateTypesExist)
{
    using bazel::tools::cpp::runfiles::Runfiles;
    std::string               error;
    std::unique_ptr<Runfiles> runfiles(Runfiles::CreateForTest(&error));
    ASSERT_TRUE(runfiles != nullptr) << error;
    std::vector<std::string> filesToCheck = {"src/entities/destination/Destination.h",
                                             "src/entities/destination/BaseDestination.h",
                                             "src/entities/destination/BaseDestination.cpp",
                                             "src/entities/destination/Lake.cpp",
                                             "src/entities/destination/Lake.h",
                                             "src/entities/destination/Mountain.cpp",
                                             "src/entities/destination/Mountain.h",
                                             "src/entities/destination/SeaSide.cpp",
                                             "src/entities/destination/SeaSide.h",
                                             "src/entities/competition/Competition.h",
                                             "src/entities/competition/CompetitionImpl.h",
                                             "src/entities/competition/CompetitionImpl.cpp",
                                             "src/entities/car/Car.h",
                                             "src/entities/car/BaseCar.h",
                                             "src/entities/car/BaseCar.cpp",
                                             "src/entities/car/Tesla.cpp",
                                             "src/entities/car/Tesla.h",
                                             "src/entities/car/Hyundai.cpp",
                                             "src/entities/car/Hyundai.h",
                                             "src/entities/car/VW.cpp",
                                             "src/entities/car/VW.h",
                                             "src/entities/car/Dacia.cpp",
                                             "src/entities/car/Dacia.h",
                                             "src/entities/repositories/DestinationRepository.h",
                                             "src/entities/repositories/DestinationRepository.cpp",
                                             "src/entities/repositories/Repository.h"};


    for (const auto& file : filesToCheck)
    {
        std::string filePath = runfiles->Rlocation("_main/" + file);
        ASSERT_TRUE(fileExists(filePath)) << "File '" << file << "' not present at path" << filePath << "'";
    }
}
