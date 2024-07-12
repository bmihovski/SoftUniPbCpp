#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;
class Car {
  const string brand;
  const string model;
  const int year;

 public:
  Car(const string &brand, const string &model, const int year)
      : brand(brand), model(model), year(year) {}

  string GetBrand() const { return brand; }
  string GetModel() const { return model; }
  int GetYear() const { return year; }
};

#endif  // !CAR_H
