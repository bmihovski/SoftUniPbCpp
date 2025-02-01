#ifndef SRC_ENTITIES_DESTINATION_LAKE_H_
#define SRC_ENTITIES_DESTINATION_LAKE_H_

#include <string>
#include "src/entities/destination/BaseDestination.h"
class Lake : public BaseDestination
{
private:
    static const int kLakeDistance = 25;

public:
    explicit Lake(const std::string& name);
};

#endif // SRC_ENTITIES_DESTINATION_LAKE_H_
