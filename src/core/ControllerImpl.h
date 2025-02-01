#ifndef SRC_CORE_CONTROLLERIMPL_H_
#define SRC_CORE_CONTROLLERIMPL_H_

#include "Controller.h"

class ControllerImpl : public Controller
{
public:
    ControllerImpl() = default;
    std::string AddDestination(const std::string& name, int distance) const override;
    std::string AddCar(const std::string& model, int battery_capacity, int mileage) const override;
    std::string ReachDestination(const std::string& destination_name) const override;
    std::string GetStatistics() const override;
    ~ControllerImpl() = default;
};

#endif // SRC_CORE_CONTROLLERIMPL_H_
