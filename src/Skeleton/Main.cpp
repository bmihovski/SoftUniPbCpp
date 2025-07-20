#include <cstddef>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

template <typename Container>
void ReadData(Container& delivery) {
  std::string line;
  std::getline(std::cin >> std::ws, line);
  std::stringstream ss(line);
  int num = 0;
  while (ss >> num) {
    delivery.push(num);
  }
}

int main() {
  int total_weight = 0;
  std::stack<int> packages;
  std::queue<int> couriers;
  ReadData(packages);
  ReadData(couriers);
  while (!packages.empty() && !couriers.empty()) {
    int current_pkg = packages.top();
    int current_courier = couriers.front();
    if (current_pkg == current_courier) {
      total_weight += current_pkg;
      packages.pop();
      couriers.pop();
    } else if (current_pkg > current_courier) {
      int pkg_diff = current_pkg - current_courier;
      total_weight += current_courier;
      couriers.pop();
      packages.top() = pkg_diff;
    } else if (current_courier >= current_pkg) {
      int courier_diff = current_courier - (2 * current_pkg);
      if (courier_diff > 0) {
        couriers.pop();
        couriers.push(courier_diff);
      } else {
        couriers.pop();
      }
      total_weight += current_pkg;
      packages.pop();
    }
  }
  std::cout << "Total weight: " << total_weight << " kg" << std::endl;
  if (!couriers.empty()) {
    std::cout << "Couriers are still on duty:  ";
    bool is_first = true;
    while (!couriers.empty()) {
      if (!is_first) {
        std::cout << ", ";
      } else {
        is_first = false;
      }
      std::cout << couriers.front();
      couriers.pop();
    }
    std::cout << std::endl;
  } else if (!packages.empty()) {
    std::cout << "Unfortunately, there are no more available couriers to "
                 "deliver the following packages: ";
    std::stack<int> packages_reversed;
    while (!packages.empty()) {
      packages_reversed.push(packages.top());
      packages.pop();
    }
    packages = packages_reversed;
    bool is_first = true;
    while (!packages.empty()) {
      if (!is_first) {
        std::cout << ", ";
      } else {
        is_first = false;
      }
      std::cout << packages.top();
      packages.pop();
    }
    std::cout << std::endl;
  } else {
    std::cout << "Congratulations, all packages were delivered successfully by "
                 "the couriers today."
              << std::endl;
  }

  return 0;
}
