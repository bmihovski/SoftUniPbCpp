
#ifndef _SRC_SKELETON_COMPANY_H
#define _SRC_SKELETON_COMPANY_H
#include <sstream>
#include <string>

class Company {
 private:
  int id;
  std::string name;

 public:
  Company() = default;
  Company(int id, const std::string& name) : id(id), name(name) {}
  std::string ToString() const {
    std::ostringstream stream;
    stream << name << " " << id;
    return stream.str();
  }
  std::string GetName() const { return this->name; }

  int GetId() const { return this->id; }
};

#endif  //_SRC_SKELETON_COMPANY_H_
