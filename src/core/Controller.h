#ifndef SRC_CORE_CONTROLLER_H_
#define SRC_CORE_CONTROLLER_H_

#include <string>

class Controller
{
public:
    virtual std::string addDestination(const std::string& name, int distance) const              = 0;
    virtual std::string addCar(const std::string& model, int batteryCapacity, int mileage) const = 0;
    virtual std::string reachDestination(const std::string& destinationName) const               = 0;
    virtual std::string getStatistics() const                                                    = 0;
    virtual ~Controller()                                                                        = default;
};

#endif // SRC_CORE_CONTROLLER_H_
