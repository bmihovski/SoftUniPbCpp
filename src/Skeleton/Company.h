#ifndef _SRC_SKELETON_COMPANY_H
#define _SRC_SKELETON_COMPANY_H
#include <exception>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

class Company {
 private:
  std::string name;
  std::vector<std::pair<char, char>> employees;

 public:
  Company() = default;
  Company(std::string const& name,
          std::vector<std::pair<char, char>> const& employees)
      : name(name), employees(employees) {}

  std::vector<std::pair<char, char>> GetEmployee() const {
    return this->employees;
  }
  std::string GetName() const { return this->name; }
  friend std::ostream& operator<<(std::ostream& output, const Company& company);
  friend std::istream& operator>>(std::istream& input, Company& company);
  friend bool operator==(const Company& lhs, const Company& rhs);
};

inline bool operator==(const Company& lhs, const Company& rhs) {
  return lhs.name == rhs.name && lhs.employees == rhs.employees;
}

inline std::ostream& operator<<(std::ostream& output, const Company& comp) {
  output << comp.name << " (";
  for (size_t i = 0; i < comp.employees.size(); ++i) {
    const auto& [first, last] = comp.employees[i];
    output << first << "." << last << ".";
    if (i < comp.employees.size() - 1) {
      output << ",";
    }
  }
  output << ")";
  return output;
}

inline std::istream& operator>>(std::istream& input, Company& comp) {
  if (!input) {
    return input;
  }

  input >> comp.name;
  std::vector<std::pair<char, char>> employees;
  char current = 0;
  input >> current;  // read first (

  // Handle empty employee list case
  input >> current;
  if (current == ')') {
    comp.employees = employees;
    return input;
  }

  // Put back the character we just read
  input.putback(current);

  while (input >> current && current != ')') {
    char first_initial = current;
    char dot1, second_initial, dot2;

    if (!(input >> dot1) || dot1 != '.') {
      throw std::exception();
    }
    if (!(input >> second_initial)) {
      throw std::exception();
    }
    if (!(input >> dot2) || dot2 != '.') {
      throw std::exception();
    }

    employees.emplace_back(first_initial, second_initial);

    // Check for comma or closing parenthesis
    input >> current;
    if (current == ')') {
      break;
    } else if (current != ',') {
      throw std::exception();
    }
  }

  comp.employees = employees;
  return input;
}
#endif  //_SRC_SKELETON_COMPANY_H_
