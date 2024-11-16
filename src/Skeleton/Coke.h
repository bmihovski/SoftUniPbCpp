#ifndef SRC_SKELETON_COKE_H_
#define SRC_SKELETON_COKE_H_

class Coke {
 private:
  double milliliters;

 public:
  static const double CALORIES_PER_100_GRAMS = 44.;
  static const double DENSITY = .6;
  explicit Coke(double milliliters);
  double getMilliliters();
}
#endif  // SRC_SKELETON_COKE_H_
