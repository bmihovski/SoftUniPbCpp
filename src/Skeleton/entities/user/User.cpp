#include "User.h"

#include <uuid/uuid.h>

#include <string>

User::User() {}

User::User(const uuid_t& id, const std::string& username,
           const std::string& password)
    : id(id), username(username), password(password) {}
