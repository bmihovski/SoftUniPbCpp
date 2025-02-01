#ifndef SRC_ENTITIES_CAR_BASECAR_H_
#define SRC_ENTITIES_CAR_BASECAR_H_

#include <string>
#include "Car.h"

class BaseCar : public Car
{
private:
    std::string model_;
    int         batteryCapacity_;
    int         mileage_;
    void        SetModel(const std::string& model);
    void        SetMileage(int mileage);
    void        SetBatteryCapacity(int battery_capacity);

public:
    BaseCar(const std::string& model, int battery_capacity);
    ~BaseCar() override = 0;
    std::string GetModel() const override;
    int         GetMileage() const override;
    int         GetBatteryCapacity() const override;
    void        Drive() override;
};

#endif // SRC_ENTITIES_CAR_BASECAR_H_
