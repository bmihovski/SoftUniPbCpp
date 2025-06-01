#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  int num_elem = 0;
  std::cin >> num_elem;
  std::vector<int> elems;
  elems.reserve(num_elem);
  std::string input;
  std::getline(std::cin >> std::ws, input);
  std::stringstream iss(input);
  int temp = 0;
  while (iss >> temp) {
    elems.push_back(temp);
  }

  while (elems.size() > 1) {
    std::vector<int> condensed;
    for (size_t i = 0; i < elems.size() - 1; ++i) {
      condensed.push_back(elems[i] + elems[i + 1]);
    }
    elems = condensed;
  }
  std::cout << elems[0] << std::endl;
  return 0;
}
