#ifndef AIRSHIP_H_
#define AIRSHIP_H_

#include <vector>
#include <memory>

enum class AirShipType
{
    BATTLE_CRUSER = 0,
    VIKING        = 1,

    CARRIER       = 2,
    PHOENIX       = 3
};

class AirShip
{
    public:
        AirShip(const AirShipType type,
                const int         maxHealth,
                const int         damage,
                const int         shipId);

        virtual ~AirShip() = default;

        virtual void takeDamage(const int damage) = 0;

        virtual void finishTurn() = 0;

        virtual void dealDamage(
                       std::vector<std::unique_ptr<AirShip>> & enemyFleet) = 0;

        bool isAlive() const;

        AirShipType getAirShipType() const;

        int getAirShipId() const;

        int getCurrHealth() const;

    protected:
        AirShipType _airShipType;
        int         _maxHealth;
        int         _currHealth;
        int         _damage;
        int         _shipId;
};

#endif /* AIRSHIP_H_ */
