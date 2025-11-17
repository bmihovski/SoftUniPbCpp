#ifndef SRC_SKELETON_UTILS_H_
#define SRC_SKELETON_UTILS_H_

#include <iostream>

#include "AirShip.h"
#include "Skeleton/BattleField.h"

inline std::string _resolveShipName(const AirShipType& type) {
  switch (type) {
    case AirShipType::VIKING:
      return "Viking";
    case AirShipType::BATTLE_CRUSER:
      return "BattleCruser";
    case AirShipType::PHOENIX:
      return "Phoenix";
    case AirShipType::CARRIER:
      return "Carrier";
    default:
      return "Unknown";
  }
}

inline void printShipKilledInfo(const AirShip* atackingShip,
                                const AirShip& defendedShip) {
  std::string resolvedName = _resolveShipName(atackingShip->getAirShipType());
  std::cout << resolvedName << " with ID: " << atackingShip->getAirShipId()
            << " killed enemy airship with ID: " << defendedShip.getAirShipId()
            << std::endl;
}

#endif  // SRC_SKELETON_UTILS_H_
