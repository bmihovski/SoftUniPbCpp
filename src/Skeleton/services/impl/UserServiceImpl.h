#ifndef SRC_SKELETON_SERVICES_IMPL_USERSERVICEIMPL_H_
#define SRC_SKELETON_SERVICES_IMPL_USERSERVICEIMPL_H_
#include <string>
#include <vector>

#include "Skeleton/services/UserService.h"
class UserServiceImpl : public UserService {
 public:
  UserServiceImpl() = default;
  std::string login(const std::string& username,
                     const std::string& passwd) override {
    return "testi";
  }
  std::string registerUser(const std::string& username,
                            const std::string& passwd) override {
    return "test";
  }
  std::string logout() override { return "test"; }
  std::vector<User> getAllUsers() override { return std::vector<User>(); }
};
#endif  // SRC_SKELETON_SERVICES_IMPL_USERSERVICEIMPL_H_
