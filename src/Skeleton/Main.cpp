#include <iostream>
#include <string>
#include <vector>

#include "Company.h"
#include "SortBy.h"

bool lessThanById(const Company& a, const Company& b) {
  return a.GetId() < b.GetId();
}

bool lessThanByName(const Company& a, const Company& b) {
  return a.GetName() > b.GetName();
}

int main() {
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(std::cin, line) && line != "end") {
    lines.push_back(line);
  }

  int numCompanies = lines.size();
  auto** companyPtrs = new Company*[numCompanies];
  for (int i = 0; i < lines.size(); ++i) {
    std::string cur_comp_str = lines[i];
    std::istringstream lineIn(cur_comp_str);
    std::string name;
    int id = 0;
    lineIn >> name >> id;
    companyPtrs[i] = new Company(id, name);
  }

  std::string sortKey;
  std::cin >> sortKey;
  if ("name" == sortKey) {
    sortBy(companyPtrs, companyPtrs + numCompanies, lessThanByName);
  } else if ("id" == sortKey) {
    sortBy(companyPtrs, companyPtrs + numCompanies, lessThanById);
  }

  for (int i = 0; i < numCompanies; ++i) {
    std::cout << companyPtrs[i]->ToString() << std::endl;
    delete companyPtrs[i];
  }

  if (companyPtrs != nullptr) {
    delete[] companyPtrs;
  }

  return 0;
}
