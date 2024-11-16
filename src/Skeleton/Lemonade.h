#ifndef SRC_SKELETON_LEMONADE_H_
#define SRC_SKELETON_LEMONADE_H_

class Lemonade {
 private:
  double milliliters;

 public:
  static const double CALORIES_PER_100_GRAMS = 53.;
  static const double DENSITY = .7;
  explicit Lemonade(double milliliters);

  double getMilliliters();
};
#endif  // SRC_SKELETON_LEMONADE_H_
