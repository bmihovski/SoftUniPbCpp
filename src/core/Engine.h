#ifndef SRC_CORE_ENGINE_H_
#define SRC_CORE_ENGINE_H_

#include "Controller.h"
#include <vector>
#include <string>

class Engine
{
private:
    Controller* controller_;

    std::string ProcessInput() const;
    std::string AddCar(std::vector<std::string>& data) const;
    std::string AddDestination(std::vector<std::string>& data) const;
    std::string ReachDestination(std::vector<std::string>& data) const;
    std::string GetStatistics() const;

public:
    explicit Engine(Controller* controller);
    void Run();
};

#endif // SRC_CORE_ENGINE_H_
