#include "Carrier.h"
Carrier::Carrier(const AirShipType type, const int health, const int damage,
                 const int maxShield, const int shieldRegenerateRate,
                 const int shipId)
    : ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate,
                     shipId) {}

void Carrier::takeDamage(const int damage) {}

void Carrier::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {}
