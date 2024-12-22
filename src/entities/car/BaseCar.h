#ifndef SRC_ENTITIES_CAR_BASECAR_H_
#define SRC_ENTITIES_CAR_BASECAR_H_

#include <string>
#include "Car.h"

class BaseCar : public Car
{
private:
    std::string model;
    int         batteryCapacity;
    int         mileage;
    void        setModel(const std::string& model);
    void        setMileage(const int mileage);
    void        setBatteryCapacity(const int batteryCapacity);

public:
    BaseCar(const std::string& model, const int batteryCapacity);
    virtual ~BaseCar() = 0;
    std::string getModel() const override;
    int         getMileage() const override;
    int         getBatteryCapacity() const override;
    void        drive() override;
};

#endif // SRC_ENTITIES_CAR_BASECAR_H_
