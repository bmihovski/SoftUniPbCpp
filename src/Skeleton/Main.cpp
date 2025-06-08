#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
size_t CountSpecialSymbols(const std::string& sentence) {
  size_t count = 0;
  for (const auto ch : sentence) {
    if (!std::isalnum(ch) && !std::isspace(ch)) {
      ++count;
    }
  }
  return count;
}
int main() {
  std::string input;
  std::vector<size_t> punct_summary;
  std::getline(std::cin, input);
  std::stringstream ss(input);
  while (std::getline(ss, input, '|')) {
    size_t count = CountSpecialSymbols(input);
    punct_summary.push_back(count);
  }
  std::sort(punct_summary.begin(), punct_summary.end(), std::less<size_t>());
  size_t current_count = punct_summary.at(0);
  size_t occur = 0;
  for (const auto& count : punct_summary) {
    if (current_count != count) {
      std::cout << current_count << " symbol sentences: " << occur << std::endl;
      current_count = count;
      occur = 1;
    } else {
      occur++;
    }
  }
  std::cout << current_count << " symbol sentences: " << occur << std::endl;
  return 0;
}
