#ifndef SRC_CONSTANTMESSAGES_H_
#define SRC_CONSTANTMESSAGES_H_
#include <string>
namespace ConstanMessages
{
constexpr char destinationAdded[] = "Successfully added destination %s %s.";
constexpr char carAdded[]         = "Successfully added car %s %s.";
constexpr char voyageOver[]       = "The voyage to %s is over. %d cars dropped out of the voyage.";
constexpr char carsTookPart[]     = "Cars that took part in competition to %s:";
constexpr char finalCarInfo[]     = R"(
                        *%s %s
                        **Battery capacity: %dkWh.
                        **Mileage: %dkm.)";
}; // namespace ConstanMessages

#endif // CONSTANT_MESSAGES_H_
