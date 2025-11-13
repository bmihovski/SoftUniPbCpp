#ifndef BATTLECRUSER_H_
#define BATTLECRUSER_H_

#include "TerranAirShip.h"

class BattleCruser : public TerranAirShip
{
    public:
        BattleCruser(const AirShipType type,
                     const int         health,
                     const int         damage,
                     const int         shipId);

        virtual ~BattleCruser() = default;

        virtual void dealDamage(
                  std::vector<std::unique_ptr<AirShip>> & enemyFleet) override;

    private:
        enum BattleCruserDefines
        {
            YAMATO_CANNON_LOADING_TIME = 4 //4 turns and shoots on the 5th
        };
};

#endif /* BATTLECRUSER_H_ */
