#ifndef SRC_ENTITIES_DESTINATION_DESTINATION_H_
#define SRC_ENTITIES_DESTINATION_DESTINATION_H_

#include <string>
#include <vector>
#include "src/entities/car/Car.h"

class Destination
{

public:
    virtual ~Destination()                         = default;
    virtual std::vector<Car*>& GetCars()           = 0;
    virtual std::string        GetName() const     = 0;
    virtual int                GetDistance() const = 0;
};

#endif // SRC_ENTITIES_DESTINATION_DESTINATION_H_
