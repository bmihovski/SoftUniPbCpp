#ifndef SRC_CORE_CONTROLLER_H_
#define SRC_CORE_CONTROLLER_H_

#include <string>

class Controller
{
public:
    virtual std::string AddDestination(const std::string& name, int distance) const               = 0;
    virtual std::string AddCar(const std::string& model, int battery_capacity, int mileage) const = 0;
    virtual std::string ReachDestination(const std::string& destination_name) const               = 0;
    virtual std::string GetStatistics() const                                                     = 0;
    virtual ~Controller()                                                                         = default;
};

#endif // SRC_CORE_CONTROLLER_H_
