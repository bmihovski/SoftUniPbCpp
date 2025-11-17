#include "BattleCruser.h"

#include "AirShip.h"
#include "TerranAirShip.h"
#include "Utils.h"

BattleCruser::BattleCruser(const AirShipType type, const int health,
                           const int damage, const int shipId)
    : TerranAirShip(type, health, damage, shipId) {}

void BattleCruser::dealDamage(
    std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  if (enemyFleet.empty()) {
    return;
  }
  auto lastShip = enemyFleet.back().get();
  auto currentDamage = _damage;

  // Check if it's a Yamato Cannon turn (every 5th turn)
  if (_passedTurns % (YAMATO_CANNON_LOADING_TIME + 1) == 0) {
    currentDamage *= 5;
  }

  if (lastShip->isAlive()) {
    lastShip->takeDamage(currentDamage);
    if (!lastShip->isAlive()) {
      printShipKilledInfo(this, *lastShip);
      enemyFleet.pop_back();
    }
  }
}
