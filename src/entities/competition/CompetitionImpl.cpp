#include "CompetitionImpl.h"

CompetitionImpl::~CompetitionImpl() = default;

void CompetitionImpl::startVoyage(const Destination& destination, const std::vector<Car*>& cars)
{
    for (Car* car : cars)
    {
        while (car->getMileage() < destination.getDistance())
        {
            if (car->getBatteryCapacity() < 15)
            {
                break;
            }
            car->drive();
            if (car->getBatteryCapacity() <= 0)
            {
                break;
            }
        }
    }
}
