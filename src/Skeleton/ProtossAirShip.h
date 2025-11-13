#ifndef PROTOSSAIRSHIP_H_
#define PROTOSSAIRSHIP_H_

#include "AirShip.h"

class ProtossAirShip : public AirShip
{
    public:
        ProtossAirShip(const AirShipType type,
                       const int         health,
                       const int         damage,
                       const int         maxShield,
                       const int         shieldRegenerateRate,
                       const int         shipId);

        virtual ~ProtossAirShip() = default;

        virtual void takeDamage(const int damage) override;

        virtual void finishTurn() override;

    protected:
        int _maxShield;
        int _currShield;
        int _shieldRegenerateRate;
};

#endif /* PROTOSSAIRSHIP_H_ */
