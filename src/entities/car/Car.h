#ifndef SRC_ENTITIES_CAR_CAR_H_
#define SRC_ENTITIES_CAR_CAR_H_

#include <string>

class Car
{
public:
    virtual ~Car() = default;
    int         getBatteryCapacity() const;
    std::string getModel() const;
    int         getMileage() const;
    void        drive();
};

#endif // SRC_ENTITIES_CAR_CAR_H_
