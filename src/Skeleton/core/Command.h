#ifndef SRC_SKELETON_CORE_COMMAND_H__
#define SRC_SKELETON_CORE_COMMAND_H__
#include <stdexcept>
#include <string>
enum class Command {
  Login,
  Register,
  Logout,
  NewWallet,
  MyWallets,
  ChangeWalletStatus,
  Deposit,
  Transfer,
  Exit
};
inline Command valueOfCommand(const std::string& command) {
  if (command == "Login") {
    return Command::Login;
  } else if (command == "Register") {
    return Command::Register;
  } else if (command == "Logout") {
    return Command::Logout;
  } else if (command == "NewWallet") {
    return Command::NewWallet;
  } else if (command == "MyWallets") {
    return Command::MyWallets;
  } else if (command == "ChangeWalletStatus") {
    return Command::ChangeWalletStatus;
  } else if (command == "Deposit") {
    return Command::Deposit;
  } else if (command == "Transfer") {
    return Command::Transfer;
  } else if (command == "Exit") {
    return Command::Exit;
  }
  throw std::invalid_argument("Invalid command!");
}

#endif  // SRC_SKELETON_CORE_COMMAND_H__
