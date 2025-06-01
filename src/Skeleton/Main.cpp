#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

void PrintTrain(const std::vector<std::string>& train) {
  std::cout << "|";
  for (const auto& vagon : train) {
    std::cout << vagon << "|";
  }
  std::cout << std::endl;
}

int main() {
  std::string input;
  std::vector<std::string> train_start;
  while (std::getline(std::cin >> std::ws, input) && input != "end") {
    if (input == "empty") {
      train_start.push_back(" ");
    } else {
      train_start.push_back(input);
    }
  }
  if (train_start.empty()) {
    return 0;
  }
  while (true) {
    std::string command;
    std::getline(std::cin >> std::ws, command);
    std::stringstream ss(command);

    std::string command_key;
    ss >> command_key;
    if (command_key == "E") {
      break;
    }
    if (command_key == "P") {
      PrintTrain(train_start);
    } else if (command_key == "M") {
      int from = 0;
      int to = 0;
      ss >> from >> to;
      const int old_vagon_position = from - 1;
      ss >> command_key;
      const int new_vagon_position = to - 1;
      const std::string vagon_name = train_start[old_vagon_position];
      train_start.erase(train_start.begin() + old_vagon_position);
      train_start.insert(train_start.begin() + new_vagon_position, vagon_name);
      PrintTrain(train_start);
    } else if (command_key == "L") {
      int pos = 0;
      ss >> pos;
      const int position_to_remove = pos - 1;
      train_start.erase(train_start.begin() + position_to_remove);
      PrintTrain(train_start);
    }
  }

  return 0;
}
