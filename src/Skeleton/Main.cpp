#include <cstdlib>
#include <iostream>
#include <ostream>

double AddedPointsAfterPreviousDay(const double points_previous_day) {
  double added_points = 0;
  added_points += points_previous_day * .05;
  return added_points;
}

double CalculateDiscountAtTheEnd(const double total_expenses,
                                 const double total_points,
                                 const int target_points) {
  double discount = .0;
  if (total_points >= target_points) {
    discount = total_expenses * .25;
  } else {
    discount = total_expenses * .1;
  }
  return discount;
}

int main() {
  int days = 0;
  int target_points = 0;
  int swimmers_count = 0;
  double hotel_price_per_day_per_swimmer = .0;
  double participation_fee_per_swimmer = .0;
  double total_expenses = .0;
  double total_hotel = .0;
  double total_participation_fee = .0;
  double total_points = 0;

  std::cin >> days >> target_points >> swimmers_count >>
      hotel_price_per_day_per_swimmer >> participation_fee_per_swimmer;
  total_hotel = days * (hotel_price_per_day_per_swimmer * swimmers_count);
  total_participation_fee = swimmers_count * participation_fee_per_swimmer;
  total_expenses = total_hotel + total_participation_fee;
  double points_previous_day = 0;

  for (int start_day = 1; start_day <= days; ++start_day) {
    double points_current_day = 0;
    std::cin >> points_current_day;
    if (start_day > 1) {
      points_current_day += AddedPointsAfterPreviousDay(points_previous_day);
    }
    total_points += points_current_day;
    points_previous_day = points_current_day;
  }
  double const discount =
      CalculateDiscountAtTheEnd(total_expenses, total_points, target_points);
  total_expenses = std::abs(total_expenses - discount);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(2);
  std::cout << "Money left to pay: " << total_expenses << " BGN." << std::endl;
  if (total_points >= target_points) {
    std::cout << "The championship was successful!" << std::endl;
  } else {
    std::cout << "The championship was not successful." << std::endl;
  }

  return 0;
}
