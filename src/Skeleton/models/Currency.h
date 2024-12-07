#ifndef SRC_SKELETON_MODELS_CURRENCY_H__
#define SRC_SKELETON_MODELS_CURRENCY_H__
#include <stdexcept>
enum Currency { USD, EUR, BTC, BGN, GBP, JPY };
inline Currency valueOfCurrency(const std::string& currency) {
  if (currency == "USD") {
    return Currency::USD;
  } else if (currency == "EUR") {
    return Currency::EUR;
  } else if (currency == "BTC") {
    return Currency::BTC;
  } else if (currency == "BGN") {
    return Currency::BGN;
  } else if (currency == "GBP") {
    return Currency::GBP;
  } else if (currency == "JPY") {
    return Currency::JPY;
  }
  throw std::invalid_argument("Invalid currency!");
}
#endif  // SRC_SKELETON_MODELS_CURRENCY_H__
