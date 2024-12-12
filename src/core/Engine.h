#ifndef SRC_CORE_ENGINE_H_
#define SRC_CORE_ENGINE_H_

#include "Controller.h"
#include <vector>
#include <string>

class Engine
{
private:
    Controller* controller;

    std::string processInput() const;
    std::string addCar(std::vector<std::string>& data) const;
    std::string addDestination(std::vector<std::string>& data) const;
    std::string reachDestination(std::vector<std::string>& data) const;
    std::string getStatistics() const;

public:
    explicit Engine(Controller* controller);
    void run();
};

#endif // SRC_CORE_ENGINE_H_
