#ifndef SRC_SORT_BY_H
#define SRC_SORT_BY_H

#include "Company.h"

inline static void sortBy(
    Company** start_comp, Company** end_comp,
    std::function<bool(const Company& a, const Company& b)> const& comparator) {
  std::sort(start_comp, end_comp,
            [&comparator](const Company* a, const Company* b) {
              return comparator(*a, *b);
            });
  return;
}

#endif  // SRC_SORT_BY_H
