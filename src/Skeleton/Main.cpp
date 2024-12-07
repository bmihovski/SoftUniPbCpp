#include <iostream>
#include <memory>

#include "Skeleton/core/SessionManager.h"
#include "Skeleton/core/impl/SessionManagerImpl.h"
#include "Skeleton/services/UserService.h"
#include "Skeleton/services/WalletService.h"
#include "Skeleton/services/impl/UserServiceImpl.h"
#include "Skeleton/services/impl/WalletServiceImpl.h"
#include "core/Engine.h"

// Function that call Print of all Getters

int main() {
  std::shared_ptr<SessionManager<User>> sessionManager =
      std::make_shared<SessionManagerImpl<User>>();
  std::shared_ptr<UserService> userService =
      std::make_shared<UserServiceImpl>();
  std::shared_ptr<WalletService> walletService =
      std::shared_ptr<WalletServiceImpl>();
  std::shared_ptr<Engine> engine = std::make_shared<Engine>(
      std::cin, sessionManager, userService, walletService);
  engine->run();
  return 0;
}
