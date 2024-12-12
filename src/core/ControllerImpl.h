#ifndef SRC_CORE_CONTROLLERIMPL_H_
#define SRC_CORE_CONTROLLERIMPL_H_

#include "Controller.h"

class ControllerImpl : public Controller
{
public:
    ControllerImpl() = default;
    std::string addDestination(const std::string& name, int distance) const override;
    std::string addCar(const std::string& model, int batteryCapacity, int mileage) const override;
    std::string reachDestination(const std::string& destinationName) const override;
    std::string getStatistics() const override;
    ~ControllerImpl() = default;
};

#endif // SRC_CORE_CONTROLLERIMPL_H_
