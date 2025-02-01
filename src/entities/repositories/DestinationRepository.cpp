#include <algorithm>
#include <memory>
#include <optional>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "DestinationRepository.h"
#include "src/entities/destination/Destination.h"


using std::unique_ptr;

DestinationRepository::DestinationRepository()  = default;
DestinationRepository::~DestinationRepository() = default;

void DestinationRepository::Add(std::unique_ptr<Destination> destination)
{
    std::cout << "Adding destination: " << destination->GetName() << std::endl;
    auto duplicate_destination = std::find_if(this->destinations_.begin(),
                                              this->destinations_.end(),
                                              [&destination](const std::unique_ptr<Destination>& dest)
                                              { return dest->GetName() == destination->GetName(); });
    if (duplicate_destination != this->destinations_.end())
    {
        std::cout << "Destination already exists." << std::endl;
        return;
    }
    this->destinations_.push_back(std::move(destination));
}

bool DestinationRepository::Remove(const Destination& destination)
{
    if (destinations_.empty())
    {
        return false;
    }
    auto found_it = std::remove_if(destinations_.begin(),
                                   destinations_.end(),
                                   [&destination](unique_ptr<Destination> const& dest)
                                   { return dest->GetName() == destination.GetName(); });
    if (found_it != destinations_.end())
    {
        destinations_.erase(found_it, this->destinations_.end());
        return true;
    }

    return false;
}

std::optional<Destination*> DestinationRepository::ByName(const std::string& name) const
{
    auto found_it = std::find_if(this->destinations_.begin(),
                                 this->destinations_.end(),
                                 [&name](const std::unique_ptr<Destination>& dest) { return dest->GetName() == name; });
    if (found_it != this->destinations_.end())
    {
        return found_it->get();
    }

    return std::nullopt;
}

std::vector<Destination*> DestinationRepository::GetCollection() const
{
    std::vector<Destination*> raw_destinations;
    raw_destinations.reserve(this->destinations_.size());
    for (const auto& dest : this->destinations_)
    {
        raw_destinations.push_back(dest.get());
    }
    return raw_destinations;
}
