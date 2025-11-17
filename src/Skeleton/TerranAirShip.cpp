#include "TerranAirShip.h"

#include "AirShip.h"

TerranAirShip::TerranAirShip(const AirShipType type, const int maxHealth,
                             const int damage, const int shipId)
    : AirShip(type, maxHealth, damage, shipId), _passedTurns(1) {}
void TerranAirShip::takeDamage(const int damage) {
  if (damage < 0) {
    return;
  }

  _currHealth -= damage;
  if (0 > _currHealth) {
    _currHealth = 0;
  }
}
void TerranAirShip::finishTurn() { _passedTurns++; }
