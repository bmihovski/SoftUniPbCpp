#include <string>

class LogMessages {
 public:
  static const char SUCCESSFULLY_REGISTERED[];

  static const char SUCCESSFULLY_LOGGED_IN[];
  static const char SUCCESSFULLY_LOGGED_OUT[];

  static const char ZERO_WALLETS[];

  static const char SUCCESSFULLY_DEPOSITED_AMOUNT[];

  static const char SUCCESSFULLY_CHANGED_WALLET_STATUS[];
  static const char SUCCESSFUL_FUNDS_TRANSFER[];
};
const char LogMessages::SUCCESSFULLY_REGISTERED[] =

    "[LOG] New user \"%s\" registered successfully and logged in.";
const char LogMessages::SUCCESSFULLY_LOGGED_IN[] =
    "[LOG] User %s successfully logged in.";
const char LogMessages::SUCCESSFULLY_LOGGED_OUT[] =

    "[LOG] User %s successfully logged out.";
const char LogMessages::ZERO_WALLETS[] =
    "[LOG] No wallets found. You may create one.";
const char LogMessages::SUCCESSFULLY_DEPOSITED_AMOUNT[] =
    "[LOG] Deposit successful! Your new balance is: %s %s.";
const char LogMessages::SUCCESSFULLY_CHANGED_WALLET_STATUS[] =
    "[LOG] Wallet status successfully changed to %s.";
const char LogMessages::SUCCESSFUL_FUNDS_TRANSFER[] =
    "[LOG] %s transferred %.2f to %s.\n[LOG] Left balance in this wallet %.2f";
