#ifndef SRC_SKELETON_ENTITIES_USER_USER_H__
#define SRC_SKELETON_ENTITIES_USER_USER_H__
#include <uuid/uuid.h>

#include <string>
class User {
 private:
  uuid_t id;
  std::string username;
  std::string password;

 public:
  User();
  User(const uuid_t& id, const std::string& username,
       const std::string& password);
};
#endif  // SRC_SKELETON_ENTITIES_USER_USER_H__
