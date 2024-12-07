#include "Engine.h"

#include <exception>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "Skeleton/core/Command.h"
#include "Skeleton/core/SessionManager.h"
#include "Skeleton/entities/user/User.h"
#include "Skeleton/models/Currency.h"
#include "Skeleton/services/WalletService.h"

Engine::Engine(std::istream& input,
               std::shared_ptr<SessionManager<User>> sessionManager,
               std::shared_ptr<UserService> userService,
               std::shared_ptr<WalletService> walletService)
    : input(input),
      sessionManager(sessionManager),
      userService(userService),
      walletService(walletService) {}

void Engine::run() {
  std::cout << "Welcome to Smart Wallet" << std::endl;
  while (true) {
    std::string result;
    try {
      result = processInput();
      if (result == "Exit") {
        break;
      }
      std::cout << "\033[0;34m" << result << "\033[0m" << std::endl;
    } catch (std::exception& e) {
      result = e.what();
      std::cerr << result << std::endl;
    }
  }
}

std::string& Engine::processInput() {
  std::string result = "";
  std::vector<std::string> tokens;
  std::string token;
  std::getline(input >> std::ws, token);
  std::istringstream ss(token);
  Command command = valueOfCommand(ss.str());
  while (ss >> token) {
    tokens.push_back(token);
  }
  switch (command) {
    case Command::Login:
      result = userService->login(tokens[0], tokens[1]);
      break;
    case Command::Register:
      result = userService->registerUser(tokens[0], tokens[1]);
      break;
    case Command::Logout:
      result = userService->logout();
      break;
    case Command::NewWallet: {
      Currency currentCurrency = valueOfCurrency(tokens[0]);
      result = walletService->createNewWallet(currentCurrency, tokens[1]);
      break;
    }
    case Command::MyWallets:
      result = walletService->getMyWallets();
      break;
    case Command::ChangeWalletStatus:
      result = walletService->changeWalletStatus(tokens[0], tokens[1]);
      break;
  }
}
