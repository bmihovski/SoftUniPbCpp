#ifndef SRC_ENTITIES_REPOSITORIES_DESTINATIONREPOSITORY_H_
#define SRC_ENTITIES_REPOSITORIES_DESTINATIONREPOSITORY_H_

#include <memory>
#include <optional>
#include <string>
#include <vector>
#include "Repository.h"
#include "src/entities/destination/Destination.h"

using DestinationRepoBase = Repository<Destination>;

class DestinationRepository : public DestinationRepoBase
{
private:
    std::vector<Destination*> destinations;

public:
    DestinationRepository();
    ~DestinationRepository();
    void                        add(Destination* destination) override;
    std::vector<Destination*>   getCollection() const override;
    bool                        remove(const Destination& destination) override;
    std::optional<Destination*> byName(const std::string& name) const override;
};
#endif // SRC_ENTITIES_REPOSITORIES_DESTINATIONREPOSITORY_H_
