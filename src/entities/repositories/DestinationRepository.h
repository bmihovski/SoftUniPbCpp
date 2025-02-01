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
    std::vector<std::unique_ptr<Destination>> destinations_;

public:
    DestinationRepository();
    ~DestinationRepository();
    void                        Add(std::unique_ptr<Destination> destination) override;
    std::vector<Destination*>   GetCollection() const override;
    bool                        Remove(const Destination& destination) override;
    std::optional<Destination*> ByName(const std::string& name) const override;
};
#endif // SRC_ENTITIES_REPOSITORIES_DESTINATIONREPOSITORY_H_
