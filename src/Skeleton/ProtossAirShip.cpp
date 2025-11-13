#include "ProtossAirShip.h"

ProtossAirShip::ProtossAirShip(const AirShipType type, const int health,
                               const int damage, const int maxShield,
                               const int shieldRegenerateRate, const int shipId)
    : AirShip(type, health, damage, shipId),
      _maxShield(maxShield),
      _shieldRegenerateRate(shieldRegenerateRate) {}

void ProtossAirShip::takeDamage(const int damage) {
  if (_currShield >= 0) {
    _currShield -= damage;
  } else {
    _currHealth -= damage;
  }
}

void ProtossAirShip::finishTurn() {}
