#ifndef SRC_SKELETON_CORE_ENGINE_H__
#define SRC_SKELETON_CORE_ENGINE_H__
#include <iostream>
#include <memory>
#include <string>

#include "../services/UserService.h"
#include "../services/WalletService.h"
#include "SessionManager.h"

class Engine {
 private:
  std::istream& input;
  std::shared_ptr<SessionManager<User>> sessionManager;
  std::shared_ptr<UserService> userService;
  std::shared_ptr<WalletService> walletService;
  std::string& processInput();

 public:
  explicit Engine(std::istream& input,
                  std::shared_ptr<SessionManager<User>> sessionManager,
                  std::shared_ptr<UserService> userService,
                  std::shared_ptr<WalletService> walletService);
  void run();
};

#endif  // SRC_SKELETON_CORE_ENGINE_H__
