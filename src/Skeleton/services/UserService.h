#ifndef SRC_SKELETON_SERVICES_USERSERVICE_H__
#define SRC_SKELETON_SERVICES_USERSERVICE_H__
#include <string>
#include <vector>

#include "../entities/user/User.h"
class UserService {
 public:
  virtual std::string login(const std::string& username,
                            const std::string& password) = 0;
  virtual std::string registerUser(const std::string& username,
                                   const std::string& password) = 0;
  virtual std::string logout() = 0;
  virtual std::vector<User> getAllUsers() = 0;
  virtual ~UserService() = default;
};

#endif  // SRC_SKELETON_SERVICES_USERSERVICE_H__
