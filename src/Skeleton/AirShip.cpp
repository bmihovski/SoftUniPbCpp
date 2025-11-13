#include "AirShip.h"

AirShip::AirShip(const AirShipType type,
                 const int         maxHealth,
                 const int         damage,
                 const int         shipId) : _airShipType(type),
                                             _maxHealth(maxHealth),
                                             _currHealth(maxHealth),
                                             _damage(damage),
                                             _shipId(shipId)
{

}

bool AirShip::isAlive() const
{
    if(0 >= _currHealth)
    {
        return false;
    }

    return true;
}

AirShipType AirShip::getAirShipType() const
{
    return _airShipType;
}

int AirShip::getAirShipId() const
{
    return _shipId;
}

int AirShip::getCurrHealth() const
{
    return _currHealth;
}
