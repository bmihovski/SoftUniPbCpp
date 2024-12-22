#include "BaseCar.h"
#include <string>
#include <stdexcept>

BaseCar::BaseCar(const std::string& model, const int batteryCapacity) : batteryCapacity(batteryCapacity), mileage(0)
{
    setModel(model);
}

BaseCar::~BaseCar() = default;

std::string BaseCar::getModel() const
{
    return model;
}

int BaseCar::getMileage() const
{
    return mileage;
}
void BaseCar::setModel(const std::string& carModel)
{
    if (carModel.empty() || carModel == " ")
    {
        throw std::invalid_argument("Car model cannot be null or empty.");
    }
    this->model = carModel;
}

void BaseCar::setMileage(const int mileage)
{
    this->mileage = mileage;
}

void BaseCar::setBatteryCapacity(const int batteryCapacity)
{
    this->batteryCapacity = batteryCapacity;
}
int BaseCar::getBatteryCapacity() const
{
    return batteryCapacity;
}

void BaseCar::drive()
{
    int newBatteryCapacity = getBatteryCapacity() - 15;
    if (newBatteryCapacity <= 0)
    {
        setBatteryCapacity(0);
    }
    else
    {
        setBatteryCapacity(newBatteryCapacity);
        setMileage(getMileage() + 25);
    }
}
