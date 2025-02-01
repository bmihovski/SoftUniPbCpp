#include "CompetitionImpl.h"

CompetitionImpl::~CompetitionImpl() = default;

void CompetitionImpl::startVoyage(const Destination& destination, const std::vector<Car*>& cars)
{
    for (Car* car : cars)
    {
        while (car->GetMileage() < destination.GetDistance())
        {
            if (car->GetBatteryCapacity() < 15)
            {
                break;
            }
            car->Drive();
            if (car->GetBatteryCapacity() <= 0)
            {
                break;
            }
        }
    }
}
