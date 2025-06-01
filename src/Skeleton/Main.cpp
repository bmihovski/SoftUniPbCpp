#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  int num_elems = 0;
  int sum_odd = 0;
  int sum_even = 0;
  int sum_total = 0;
  int average = 0;

  std::cin >> num_elems;
  std::vector<int> elems;
  elems.reserve(num_elems);
  std::string input;
  std::getline(std::cin >> std::ws, input);
  std::stringstream ss(input);
  int val = 0;
  while (ss >> val) {
    sum_total += val;
    elems.push_back(val);
  }
  average = sum_total / num_elems;

  for (size_t start = 0; start < num_elems; ++start) {
    int cur_elem = elems[start];
    if (cur_elem > average) {
      continue;
    }
    if (start % 2 == 0) {
      sum_even += elems[start];
    } else {
      sum_odd += elems[start];
    }
  }
  std::cout << (sum_even * sum_odd) << std::endl;

  return 0;
}
