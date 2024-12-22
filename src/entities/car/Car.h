#ifndef SRC_ENTITIES_CAR_CAR_H_
#define SRC_ENTITIES_CAR_CAR_H_

#include <string>

class Car
{
public:
    virtual ~Car()                                 = default;
    virtual int         getBatteryCapacity() const = 0;
    virtual std::string getModel() const           = 0;
    virtual int         getMileage() const         = 0;
    virtual void        drive()                    = 0;
};

#endif // SRC_ENTITIES_CAR_CAR_H_
