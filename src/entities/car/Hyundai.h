#ifndef SRC_ENTITIES_CAR_HYUNDAI_H_
#define SRC_ENTITIES_CAR_HYUNDAI_H_

#include <string>
#include "BaseCar.h"

class Hyundai : public BaseCar
{
private:
    const static int initialBatteryHyundai = 60;

public:
    explicit Hyundai(const std::string& model);
};

#endif // SRC_ENTITIES_CAR_HYUNDAI_H_
