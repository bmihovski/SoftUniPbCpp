#ifndef SRC_SKELETON_CHOCOLATE_H_
#define SRC_SKELETON_CHOCOLATE_H_

class Chocolate {
 private:
  double grams;

 public:
  static const double CALORIES_PER_100_GRAMS = 575.;
  explicit Chocolate(const double grams);
  double getGrams();
};
#endif  // SRC_SKELETON_CHOCOLATE_H_
