#include "BaseDestination.h"
#include <stdexcept>
#include <string>
#include <vector>

BaseDestination::BaseDestination(const std::string& name, const int distance)
{
    setName(name);
    setDistance(distance);
    this->cars = std::vector<Car*>();
}

BaseDestination::~BaseDestination()
{
    for (auto car : cars)
    {
        delete car;
    }
}

std::string BaseDestination::getName() const
{
    return this->name;
}

int BaseDestination::getDistance() const
{
    return distance;
}


std::vector<Car*>& BaseDestination::getCars()
{
    return this->cars;
}

void BaseDestination::setName(const std::string& destination_name)
{
    if (destination_name.empty()) throw std::invalid_argument("Destination name cannot be null or empty.");

    this->name = destination_name;
}

void BaseDestination::setDistance(const int distance_to_reach)
{
    if (distance_to_reach < 0) throw std::invalid_argument("Distance cannot be a negative number!");

    this->distance = distance_to_reach;
}
