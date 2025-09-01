#ifndef SRC_SKELETON_REMOVEDUPLICATES_H
#define SRC_SKELETON_REMOVEDUPLICATES_H
#include <list>

#include "Company.h"

inline void removeDuplicates(std::list<Company *> &companies) {
  for (auto it = companies.begin(); it != companies.end(); ++it) {
    auto next_it = std::next(it);
    while (next_it != companies.end()) {
      if ((*it)->GetName() == (*next_it)->GetName() &&
          (*it)->GetEmployee() == (*next_it)->GetEmployee()) {
        next_it = companies.erase(next_it);
      } else {
        ++next_it;
      }
    }
  }
  return;
}
#endif  // SRC_SKELETON_REMOVEDUPLICATES_H
