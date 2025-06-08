#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool IsVovel(const char symbol) {
  return symbol == 'a' || symbol == 'e' || symbol == 'i' || symbol == 'o' ||
         symbol == 'u';
}

int main() {
  std::string line;
  std::vector<char> symbols;
  std::getline(std::cin, line);
  auto it_line = line.begin();
  while (it_line != line.end()) {
    symbols.push_back(*it_line);
    ++it_line;
  }
  auto it = symbols.begin();
  while (it != symbols.end()) {
    if (*it != *(it + 1) || IsVovel(*it)) {
      std::cout << *it;
    }
    ++it;
  }
  std::cout << std::endl;
  return 0;
}
