
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "traffic.h"
TrafficLight getTrafficLight(const std::string& light) {
  if (light == "GREEN") {
    return TrafficLight::GREEN;
  } else if (light == "RED") {
    return TrafficLight::RED;
  } else {
    return TrafficLight::YELLOW;
  }
}

TrafficLight switchLight(const TrafficLight& lightToSwitch) {
  switch (lightToSwitch) {
    case TrafficLight::RED:
      return TrafficLight::GREEN;
    case TrafficLight::GREEN:
      return TrafficLight::YELLOW;
    case TrafficLight::YELLOW:
      return TrafficLight::RED;
    default:
      throw std::invalid_argument("Invalid traffic light");
  }
}

std::string trafficToString(const TrafficLight& light) {
  switch (light) {
    case TrafficLight::RED:
      return "RED";
    case TrafficLight::GREEN:
      return "GREEN";
    case TrafficLight::YELLOW:
      return "YELLOW";
    default:
      throw std::invalid_argument("Invalid traffic light");
  }
}

int main(int argc, char* argv[]) {
  std::string trafficLights;
  std::vector<std::vector<TrafficLight>> allLights;
  int changes;
  std::getline(std::cin >> std::ws, trafficLights);
  std::cin >> changes;
  std::istringstream ss(trafficLights);
  std::vector<TrafficLight> lights;
  while (ss >> trafficLights) {
    lights.push_back(getTrafficLight(trafficLights));
  }
  while (changes--) {
    for (size_t start = 0; start < lights.size(); ++start) {
      auto currentLight = lights[start];
      auto nextLight = switchLight(lights[start]);
      lights[start] = nextLight;
    }
    allLights.push_back(lights);
  }
  for (const auto& ligthsChange : allLights) {
    for (const auto& currentOp : ligthsChange) {
      std::cout << trafficToString(currentOp) << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
