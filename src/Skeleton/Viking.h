#ifndef VIKING_H_
#define VIKING_H_

#include "TerranAirShip.h"

class Viking : public TerranAirShip
{
    public:
        Viking(const AirShipType type,
               const int         health,
               const int         baseDamage,
               const int         shipId);

        virtual ~Viking() = default;

        virtual void dealDamage(
                  std::vector<std::unique_ptr<AirShip>> & enemyFleet) override;
};

#endif /* VIKING_H_ */
