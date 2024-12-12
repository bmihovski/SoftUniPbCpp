#ifndef SRC_COMMON_EXCEPTIONMESSAGES_H_
#define SRC_COMMON_EXCEPTIONMESSAGES_H_
#include <string>
namespace ExceptionMessages
{
constexpr char destinationNameNullOrEmpty[] = "Destination name cannot be null or empty.";
constexpr char InvalidDestination[]         = "Invalid destination!";
constexpr char negativeDistanceValue[]      = "Distance cannot be a negative number!";
constexpr char existingDestination[]        = "The destination with this name already exists!";
constexpr char nonExistingDestination[]     = "The destination does not exist!";
constexpr char carModelNullOrEmpty[]        = "Car model cannot be null or empty.";
constexpr char invalidCar[]                 = "Invalid car!";
constexpr char existingCarBrandAndModel[]   = "A car with this brand and model already exists!";
} // namespace ExceptionMessages
#endif // SRC_COMMON_EXCEPTIONMESSAGES_H_
