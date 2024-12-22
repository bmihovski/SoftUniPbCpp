#ifndef SRC_ENTITIES_DESTINATION_BASEDESTINATION_H_
#define SRC_ENTITIES_DESTINATION_BASEDESTINATION_H_

#include "Destination.h"
#include <vector>
#include <string>

class BaseDestination : public Destination
{
private:
    std::string       name;
    int               distance;
    std::vector<Car*> cars;
    void              setName(const std::string& name);
    void              setDistance(const int distance);

public:
    virtual ~BaseDestination() = 0;
    BaseDestination(const std::string& name, int distance);
    std::vector<Car*>& getCars() override;
    std::string        getName() const override;
    int                getDistance() const override;
};

#endif // SRC_ENTITIES_DESTINATION_BASEDESTINATION_H_
