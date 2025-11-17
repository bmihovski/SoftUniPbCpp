#include "Carrier.h"

#include <memory>

#include "Phoenix.h"
#include "Utils.h"

Carrier::Carrier(const AirShipType type, const int health, const int damage,
                 const int maxShield, const int shieldRegenerateRate,
                 const int shipId)
    : ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate,
                     shipId),
      _activeInterceptors(InterceptorDefines::MAX_INTERCEPTORS) {}

void Carrier::takeDamage(const int damage) {
  ProtossAirShip::takeDamage(damage);
  if (getCurrHealth() < _maxHealth) {
    _activeInterceptors = InterceptorDefines::DAMAGED_STATUS_INTERCEPTORS;
  }
}

void Carrier::dealDamage(std::vector<std::unique_ptr<AirShip>>& enemyFleet) {
  int attacks = _activeInterceptors;
  while ((attacks--) > 0) {
    if (enemyFleet.empty()) {
      return;
    }
    auto lastShip = enemyFleet.back().get();
    if (lastShip->isAlive()) {
      int damageToDeal = this->_damage;
      lastShip->takeDamage(damageToDeal);
      if (!lastShip->isAlive()) {
        printShipKilledInfo(this, *lastShip);
        enemyFleet.pop_back();
      }
    }
  }
}
