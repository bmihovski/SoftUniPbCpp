#ifndef SRC_ENTITIES_CAR_VW_H_
#define SRC_ENTITIES_CAR_VW_H_

#include <string>
#include "BaseCar.h"

class VW : public BaseCar
{
private:
    const static int initialBatteryVW = 50;

public:
    explicit VW(const std::string& model);
};

#endif // SRC_ENTITIES_CAR_VW_H_
