#include <algorithm>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include "DestinationRepository.h"
#include "src/entities/destination/Destination.h"


DestinationRepository::DestinationRepository() {}
DestinationRepository::~DestinationRepository()
{
    for (auto dest : this->destinations)
    {
        if (dest != nullptr)
        {
            // delete dest;
        }
    }
}

void DestinationRepository::add(Destination* destination)
{
    std::cout << "Adding destination: " << destination->getName() << std::endl;
    auto duplicateDestination =
        std::find_if(this->destinations.begin(),
                     this->destinations.end(),
                     [&destination](const Destination* dest) { return dest->getName() == destination->getName(); });
    if (duplicateDestination != this->destinations.end())
    {
        std::cout << "Destination already exists." << std::endl;
        return;
    }
    this->destinations.push_back(destination);
}

bool DestinationRepository::remove(const Destination& destination)
{
    auto foundIt =
        std::remove_if(destinations.begin(),
                       destinations.end(),
                       [&destination](const Destination* dest) { return dest->getName() == destination.getName(); });
    if (foundIt != destinations.end())
    {
        delete *foundIt;
        destinations.erase(foundIt, this->destinations.end());
        return true;
    }
    else
    {
        return false;
    }
}

std::optional<Destination*> DestinationRepository::byName(const std::string& name) const
{
    auto foundIt = std::find_if(this->destinations.begin(),
                                this->destinations.end(),
                                [&name](const Destination* dest) { return dest->getName() == name; });
    if (foundIt != this->destinations.end())
    {
        return *foundIt;
    }
    else
    {
        return std::nullopt;
    }
}

std::vector<Destination*> DestinationRepository::getCollection() const
{
    return destinations;
}
