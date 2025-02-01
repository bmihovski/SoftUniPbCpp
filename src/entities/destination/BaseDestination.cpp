#include "BaseDestination.h"
#include <stdexcept>
#include <string>
#include <vector>

BaseDestination::BaseDestination(const std::string& name, const int distance) : distance_(distance)
{
    SetName(name);
    SetDistance(distance);
    this->cars_ = std::vector<Car*>();
}

BaseDestination::~BaseDestination()
{
    for (auto* car : cars_)
    {
        delete car;
    }
}

std::string BaseDestination::GetName() const
{
    return this->name_;
}

int BaseDestination::GetDistance() const
{
    return distance_;
}


std::vector<Car*>& BaseDestination::GetCars()
{
    return this->cars_;
}

void BaseDestination::SetName(const std::string& destination_name)
{
    if (destination_name.empty())
    {
        throw std::invalid_argument("Destination name cannot be null or empty.");
    }

    this->name_ = destination_name;
}

void BaseDestination::SetDistance(const int distance_to_reach)
{
    if (distance_to_reach < 0)
    {
        throw std::invalid_argument("Distance cannot be a negative number!");
    }

    this->distance_ = distance_to_reach;
}
