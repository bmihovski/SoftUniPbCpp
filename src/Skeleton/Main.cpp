#include <cmath>
#include <cstdlib>
#include <iostream>
#include <ostream>

double CalculateSetPriceForStudents(const double price_flour,
                                    const double price_egg, double price_apron,
                                    int num_students) {
  const double number_aprons = std::ceil(num_students * 1.2);
  const int discount_flour = num_students / 5;
  const double price_eggs = price_egg * (num_students * 10);
  const double price_aprons = price_apron * number_aprons;
  const double price_flours = price_flour * (num_students - discount_flour);
  return price_eggs + price_aprons + price_flours;
}

int main() {
  double budget = .0;
  int students = 0;
  double price_flour = .0;
  double price_egg = .0;
  double price_apron = .0;
  std::cin >> budget >> students >> price_flour >> price_egg >> price_apron;
  double total = CalculateSetPriceForStudents(price_flour, price_egg,
                                              price_apron, students);
  double actual_to_pay = std::abs(budget - total);
  std::cout.precision(2);
  std::cout << std::fixed;
  if (total <= budget) {
    std::cout << "Items purchased for " << total << "$." << std::endl;
  } else {
    std::cout << actual_to_pay << "$ more needed." << std::endl;
  }

  return 0;
}
