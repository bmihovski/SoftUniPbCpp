#ifndef PHOENIX_H_
#define PHOENIX_H_

#include "ProtossAirShip.h"

class Phoenix : public ProtossAirShip
{
    public:
        Phoenix(const AirShipType type,
                const int         health,
                const int         damage,
                const int         maxShield,
                const int         shieldRegenerateRate,
                const int         shipId);

        virtual ~Phoenix() = default;

        virtual void dealDamage(
                  std::vector<std::unique_ptr<AirShip>> & enemyFleet) override;
};

#endif /* PHOENIX_H_ */
