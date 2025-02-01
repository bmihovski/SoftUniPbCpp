#ifndef SRC_ENTITIES_DESTINATION_SEASIDE_H_
#define SRC_ENTITIES_DESTINATION_SEASIDE_H_
#include <string>
#include "src/entities/destination/BaseDestination.h"

class SeaSide : public BaseDestination
{
private:
    static const int kSeaSideDistance = 80;

public:
    explicit SeaSide(const std::string& name);
};

#endif // SRC_ENTITIES_DESTINATION_SEASIDE_H_
