#ifndef SRC_ENTITIES_CAR_CAR_H_
#define SRC_ENTITIES_CAR_CAR_H_

#include <string>

class Car
{
public:
    virtual ~Car()                                 = default;
    virtual int         GetBatteryCapacity() const = 0;
    virtual std::string GetModel() const           = 0;
    virtual int         GetMileage() const         = 0;
    virtual void        Drive()                    = 0;
};

#endif // SRC_ENTITIES_CAR_CAR_H_
