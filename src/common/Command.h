#ifndef SRC_COMMON_COMMAND_H_
#define SRC_COMMON_COMMAND_H_

#include <string>
#include <unordered_map>

enum class Command
{
    AddDestination,
    AddCar,
    ReachDestination,
    GetStatistics,
    Exit
};
inline Command valueOf(const std::string& commandStr)
{
    std::unordered_map<std::string, Command> commandsMap = {{"AddDestination", Command::AddDestination},
                                                            {"AddCar", Command::AddCar},
                                                            {"ReachDestination", Command::ReachDestination},
                                                            {"GetStatistics", Command::GetStatistics},
                                                            {"Exit", Command::Exit}};

    return commandsMap[commandStr];
}

#endif // SRC_COMMON_COMMAND_H_
