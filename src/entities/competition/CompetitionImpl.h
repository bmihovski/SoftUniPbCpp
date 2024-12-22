#ifndef SRC_ENTITIES_COMPETITION_COMPETITIONIMPL_H_
#define SRC_ENTITIES_COMPETITION_COMPETITIONIMPL_H_

#include <vector>
#include "src/entities/competition/Competition.h"
#include "src/entities/destination/Destination.h"

class CompetitionImpl : public Competition
{
public:
    void startVoyage(const Destination& destination, const std::vector<Car*>& cars) override;
    ~CompetitionImpl() override;
};

#endif // SRC_ENTITIES_COMPETITION_COMPETITIONIMPL_H_
