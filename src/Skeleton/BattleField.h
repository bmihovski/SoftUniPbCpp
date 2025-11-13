#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include "AirShip.h"

#include <string>
#include <memory>

class BattleField
{
    public:
        BattleField() = default;
        virtual ~BattleField() = default;

        void generateTerranFleet(const std::string & fleetComposition);

        void generateProtossFleet(const std::string & fleetComposition);

        void startBattle();

    private:
        bool processTerranTurn();

        bool processProtossTurn();

        enum AirShipDefines
        {
            BATTLE_CRUSER_HEALTH           = 450,
            BATTLE_BRUSER_DAMAGE           = 40,

            VIKING_HEALTH                  = 150,
            VIKING_DAMAGE                  = 15,

            CARRIER_HEALTH                 = 200,
            CARRIER_SHIELD                 = 150,
            CARRIER_DAMAGE                 = 8,
            CARRIER_SHIELD_REGENERATE_RATE = 40,

            PHOENIX_HEALTH                 = 90,
            PHOENIX_SHIELD                 = 90,
            PHOENIX_DAMAGE                 = 20,
            PHOENIX_SHIELD_REGENERATE_RATE = 20
        };

        std::vector<std::unique_ptr<AirShip>> _terranFleet;
        std::vector<std::unique_ptr<AirShip>> _protossFleet;
};

#endif /* BATTLEFIELD_H_ */
