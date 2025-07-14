#include <algorithm>
#include <cstddef>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

double CalculatePrice(const double price, const int quantity) {
  return price * quantity;
}

int main() {
  size_t cities_count = 0;
  std::string line;
  std::cin >> cities_count;

  std::map<std::string, double> city_totals;

  while (std::getline(std::cin >> std::ws, line)) {
    double price = 0;
    int quantity = 0;
    std::cin >> price >> quantity;

    city_totals[line] += CalculatePrice(price, quantity);
  }

  size_t start_limit = 0;
  for (const auto& [name, total] : city_totals) {
    if (start_limit >= cities_count) {
      break;
    }
    std::cout << city_totals[name] << " " << total << std::endl;
    start_limit++;
  }

  return 0;
}
