#ifndef SRC_SKELETON_CALORIESCALCULATOR_H_
#define SRC_SKELETON_CALORIESCALCULATOR_H_

#include <string>
#include <vector>

template <typename T>
class CaloriesCalculator {
 private:
  static const std::string SUM = "Sum: %f";
  static const std::string AVERAGE = "Average: %f";

 public:
  const double sum(const std::vector<T>& products);
  const double average(const std::vector<T>& products);
  const double printSum(const std::vector<T>& sum);
  const double printAverage(const std::vector<T>& average);
};
#endif  // SRC_SKELETON_CALORIESCALCULATOR_H_
