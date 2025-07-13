#include <functional>
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
  std::map<std::string, double> city_prices;
  while (std::getline(std::cin >> std::ws, line)) {
    double price = 0;
    int quantity = 0;
    std::cin >> price >> quantity;
    city_prices[line] += CalculatePrice(price, quantity);
  }

  for (const auto& [name, total] : city_prices) {
    std::cout << name << " " << total << std::endl;
  }

  return 0;
}
