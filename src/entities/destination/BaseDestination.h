#ifndef SRC_ENTITIES_DESTINATION_BASEDESTINATION_H_
#define SRC_ENTITIES_DESTINATION_BASEDESTINATION_H_

#include "Destination.h"
#include <vector>
#include <string>

class BaseDestination : public Destination
{
private:
    std::string       name_;
    int               distance_;
    std::vector<Car*> cars_;
    void              SetName(const std::string& name);
    void              SetDistance(int distance);

public:
    ~BaseDestination() override = 0;
    BaseDestination(const std::string& name, int distance);
    std::vector<Car*>& GetCars() override;
    std::string        GetName() const override;
    int                GetDistance() const override;
};

#endif // SRC_ENTITIES_DESTINATION_BASEDESTINATION_H_
