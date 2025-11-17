#include "Phoenix.h"

#include "ProtossAirShip.h"
#include "Utils.h"

Phoenix::Phoenix(const AirShipType type, const int health, const int damage,
                 const int maxShield, const int shieldRegenerateRate,
                 const int shipId)
    : ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate,
                     shipId) {}

void Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  if (enemyFleet.empty()) {
    return;
  }
  auto lastShip = enemyFleet.back().get();
  if (lastShip->isAlive()) {
    int shipDamage = _damage;
    lastShip->takeDamage(shipDamage);
    if (!lastShip->isAlive()) {
      printShipKilledInfo(this, *lastShip);
      enemyFleet.pop_back();
    }
  }
}
