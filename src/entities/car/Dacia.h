#ifndef SRC_ENTITIES_CAR_DACIA_H_
#define SRC_ENTITIES_CAR_DACIA_H_

#include <string>
#include "BaseCar.h"

class Dacia : public BaseCar
{
private:
    std::string      model;
    static const int initialBatteryDacia = 30;

public:
    explicit Dacia(const std::string& model);
};

#endif // SRC_ENTITIES_CAR_DACIA_H_
