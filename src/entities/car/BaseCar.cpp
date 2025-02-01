#include "BaseCar.h"
#include <string>
#include <stdexcept>

BaseCar::BaseCar(const std::string& model, const int battery_capacity) : batteryCapacity_(battery_capacity), mileage_(0)
{
    SetModel(model);
}

BaseCar::~BaseCar() = default;

std::string BaseCar::GetModel() const
{
    return model_;
}

int BaseCar::GetMileage() const
{
    return mileage_;
}
void BaseCar::SetModel(const std::string& car_model)
{
    if (car_model.empty() || car_model == " ")
    {
        throw std::invalid_argument("Car model cannot be null or empty.");
    }
    this->model_ = car_model;
}

void BaseCar::SetMileage(const int mileage)
{
    this->mileage_ = mileage;
}

void BaseCar::SetBatteryCapacity(const int battery_capacity)
{
    this->batteryCapacity_ = battery_capacity;
}
int BaseCar::GetBatteryCapacity() const
{
    return batteryCapacity_;
}

void BaseCar::Drive()
{
    int const new_battery_capacity = GetBatteryCapacity() - 15;
    if (new_battery_capacity <= 0)
    {
        SetBatteryCapacity(0);
    }
    else
    {
        SetBatteryCapacity(new_battery_capacity);
        SetMileage(GetMileage() + 25);
    }
}
