#include "BattleField.h"
#include "Phoenix.h"
#include "Carrier.h"
#include "Viking.h"
#include "BattleCruser.h"

#include <iostream>

void BattleField::generateTerranFleet(const std::string & fleetComposition)
{
    const int FLEET_SIZE = static_cast<int>(fleetComposition.size());

    _terranFleet.reserve(FLEET_SIZE);

    for(int i = 0; i < FLEET_SIZE; ++i)
    {
        switch(fleetComposition[i])
        {
            case 'b':
                _terranFleet.emplace_back(new BattleCruser(
                                                    AirShipType::BATTLE_CRUSER,
                                                    BATTLE_CRUSER_HEALTH,
                                                    BATTLE_BRUSER_DAMAGE,
                                                    i));
                break;

            case 'v':
                _terranFleet.emplace_back(new Viking(AirShipType::VIKING,
                                                     VIKING_HEALTH,
                                                     VIKING_DAMAGE,
                                                     i));
                break;
        }
    }
}

void BattleField::generateProtossFleet(const std::string & fleetComposition)
{
    const int FLEET_SIZE = static_cast<int>(fleetComposition.size());

    _terranFleet.reserve(FLEET_SIZE);

    for(int i = 0; i < FLEET_SIZE; ++i)
    {
        switch(fleetComposition[i])
        {
            case 'c':
                _protossFleet.emplace_back(new Carrier(
                                              AirShipType::CARRIER,
                                              CARRIER_HEALTH,
                                              CARRIER_DAMAGE,
                                              CARRIER_SHIELD,
                                              CARRIER_SHIELD_REGENERATE_RATE,
                                              i));
                break;

            case 'p':
                _protossFleet.emplace_back(new Phoenix(
                                              AirShipType::PHOENIX,
                                              PHOENIX_HEALTH,
                                              PHOENIX_DAMAGE,
                                              PHOENIX_SHIELD,
                                              PHOENIX_SHIELD_REGENERATE_RATE,
                                              i));
                break;
        }
    }
}

void BattleField::startBattle()
{
    while(true)
    {
        if(processTerranTurn())
        {
            std::cout << "TERRAN has won!\n";
            break;
        }

        if(processProtossTurn())
        {
            std::cout << "PROTOSS has won!\n";
            break;
        }
    }
}

bool BattleField::processTerranTurn()
{
    for(std::unique_ptr<AirShip> & ship : _terranFleet)
    {
        ship->dealDamage(_protossFleet);
        ship->finishTurn();

        if(_protossFleet.empty())
        {
            return true;
        }
    }

    if(!_protossFleet.empty())
    {
        std::cout << "Last Protoss AirShip with ID: "
                  << _protossFleet.back()->getAirShipId() << " has "
                  << _protossFleet.back()->getCurrHealth() << " health left\n";
    }

    return false;
}

bool BattleField::processProtossTurn()
{
    for(std::unique_ptr<AirShip> & ship : _protossFleet)
    {
        ship->dealDamage(_terranFleet);
        ship->finishTurn();

        if(_terranFleet.empty())
        {
            return true;
        }
    }

    if(!_terranFleet.empty())
    {
        std::cout << "Last Terran AirShip with ID: "
                  << _terranFleet.back()->getAirShipId() << " has "
                  << _terranFleet.back()->getCurrHealth() << " health left\n";
    }

    return false;
}


