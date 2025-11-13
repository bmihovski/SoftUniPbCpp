#ifndef CARRIER_H_
#define CARRIER_H_

#include "ProtossAirShip.h"

class Carrier : public ProtossAirShip
{
    public:
        Carrier(const AirShipType type,
                const int         health,
                const int         damage,
                const int         maxShield,
                const int         shieldRegenerateRate,
                const int         shipId);

        virtual ~Carrier() = default;

        virtual void takeDamage(const int damage) override;

        virtual void dealDamage(
                  std::vector<std::unique_ptr<AirShip>> & enemyFleet) override;

    private:
        enum InterceptorDefines
        {
            MAX_INTERCEPTORS            = 8,
            DAMAGED_STATUS_INTERCEPTORS = 4
        };

        int _activeInterceptors;
};

#endif /* CARRIER_H_ */
