#ifndef SRC_ENTITIES_COMPETITION_COMPETITION_H_
#define SRC_ENTITIES_COMPETITION_COMPETITION_H_

#include <vector>
#include "src/entities/car/Car.h"
#include "src/entities/destination/Destination.h"

class Competition
{
public:
    virtual ~Competition()                                                                  = default;
    virtual void startVoyage(const Destination& destination, const std::vector<Car*>& cars) = 0;
};

#endif // SRC_ENTITIES_COMPETITION_COMPETITION_H_
