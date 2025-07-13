#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
  std::string line;
  std::unordered_map<std::string, std::set<int>> rooms_data;
  while (std::getline(std::cin, line) && line != "END") {
    std::stringstream ss(line);
    std::string name;
    int room_number = 0;
    ss >> name >> room_number;
    rooms_data[name].insert(room_number);
  }

  while (std::getline(std::cin, line) && line != "END") {
    auto found_record_it = rooms_data.find(line);
    if (found_record_it == rooms_data.end()) {
      std::cout << line << ": Not found!";
    } else {
      std::cout << line << ": ";
      for (const auto& room_num : found_record_it->second) {
        std::cout << room_num << " ";
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
