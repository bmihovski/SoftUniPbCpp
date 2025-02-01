#ifndef SRC_ENTITIES_DESTINATION_MOUNTAIN_H_
#define SRC_ENTITIES_DESTINATION_MOUNTAIN_H_
#include <string>
#include "src/entities/destination/BaseDestination.h"

class Mountain : public BaseDestination
{
private:
    static const int kMountainDistance = 60;

public:
    explicit Mountain(const std::string& name);
};

#endif // SRC_ENTITIES_DESTINATION_MOUNTAIN_H_
