#ifndef TERRANAIRSHIP_H_
#define TERRANAIRSHIP_H_

#include "AirShip.h"

class TerranAirShip : public AirShip
{
    public:
        TerranAirShip(const AirShipType type,
                      const int         maxHealth,
                      const int         damage,
                      const int         shipId);

        virtual ~TerranAirShip() = default;

        virtual void takeDamage(const int damage) override;

        virtual void finishTurn() override;

    protected:
        int _passedTurns;
};

#endif /* TERRANAIRSHIP_H_ */
