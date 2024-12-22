#ifndef SRC_ENTITIES_CAR_TESLA_H_
#define SRC_ENTITIES_CAR_TESLA_H_
#include <string>
#include "BaseCar.h"

class Tesla : public BaseCar
{
private:
    const static int initialBatteryTesla = 85;

public:
    explicit Tesla(const std::string& model);
};

#endif // SRC_ENTITIES_CAR_TESLA_H_
