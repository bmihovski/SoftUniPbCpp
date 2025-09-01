#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include "RemoveDuplicates.h"

int main() {
  std::istream::sync_with_stdio(false);
  std::ostream::sync_with_stdio(false);
  std::list<Company*> companies;
  std::string line;
  Company* lastCompany = nullptr;
  while (std::getline(std::cin, line) && line != "end") {
    if (line[0] != '*') {
      lastCompany = new Company();
      std::istringstream(line) >> *lastCompany;
      companies.push_back(lastCompany);
    } else {
      if (lastCompany == nullptr) {
        throw std::exception();
      }
      if (line == "*begin") {
        companies.insert(companies.begin(), lastCompany);
      } else if (line == "*end") {
        companies.insert(companies.end(), lastCompany);
      } else {
        throw std::exception();
      }
    }
  }
  removeDuplicates(companies);
  for (Company* compPtr : companies) {
    std::cout << *compPtr << std::endl;
    delete compPtr;
  }

  return 0;
}
