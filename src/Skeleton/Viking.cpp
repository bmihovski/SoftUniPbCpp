#include "Viking.h"

#include "AirShip.h"
#include "TerranAirShip.h"
#include "Utils.h"

Viking::Viking(const AirShipType type, const int health, const int baseDamage,
               const int shipId)
    : TerranAirShip(type, health, baseDamage, shipId) {}

void Viking::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  if (enemyFleet.empty()) {
    return;
  }
  auto lastShip = enemyFleet.back().get();
  int damageToDeal = _damage;
  if (lastShip->getAirShipType() == AirShipType::PHOENIX) {
    damageToDeal *= 2;
  }
  if (lastShip->isAlive()) {
    lastShip->takeDamage(damageToDeal);
    if (!lastShip->isAlive()) {
      printShipKilledInfo(this, *lastShip);
      enemyFleet.pop_back();
    }
  }
}
