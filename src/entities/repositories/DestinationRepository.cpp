#include <algorithm>
#include <memory>
#include <optional>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "DestinationRepository.h"
#include "src/entities/destination/Destination.h"


DestinationRepository::DestinationRepository()  = default;
DestinationRepository::~DestinationRepository() = default;

void DestinationRepository::add(std::unique_ptr<Destination> destination)
{
    std::cout << "Adding destination: " << destination->getName() << std::endl;
    auto duplicate_destination = std::find_if(this->destinations.begin(),
                                              this->destinations.end(),
                                              [&destination](std::unique_ptr<Destination>& dest)
                                              { return dest->getName() == destination->getName(); });
    if (duplicate_destination != this->destinations.end())
    {
        std::cout << "Destination already exists." << std::endl;
        return;
    }
    this->destinations.push_back(std::move(destination));
}

bool DestinationRepository::remove(const Destination& destination)
{
    auto found_it = std::remove_if(destinations.begin(),
                                   destinations.end(),
                                   [&destination](std::unique_ptr<Destination>& dest)
                                   { return dest->getName() == destination.getName(); });
    if (found_it != destinations.end())
    {
        destinations.erase(found_it, this->destinations.end());
        return true;
    }

    return false;
}

std::optional<Destination*> DestinationRepository::byName(const std::string& name) const
{
    auto found_it = std::find_if(this->destinations.begin(),
                                 this->destinations.end(),
                                 [&name](const std::unique_ptr<Destination>& dest) { return dest->getName() == name; });
    if (found_it != this->destinations.end())
    {
        return found_it->get();
    }

    return std::nullopt;
}

std::vector<Destination*> DestinationRepository::getCollection() const
{
    std::vector<Destination*> raw_destinations;
    raw_destinations.reserve(this->destinations.size());
    for (const auto& dest : this->destinations)
    {
        raw_destinations.push_back(dest.get());
    }
    return raw_destinations;
}
