
class SystemErrors {
 public:
  static const char INVALID_USERNAME[];

  static const char INVALID_PASSWORD[];

  static const char USER_ALREADY_LOGGED_IN[];

  static const char INCORRECT_LOGIN_CREDENTIALS[];

  static const char SUCH_USERNAME_ALREADY_EXIST[];

  static const char NO_ACTIVE_USER_SESSION_FOUND[];

  static const char INSUFFICIENT_FUNDS_IN_WALLET[];

  static const char NO_OPERATIONS_ALLOWED_FOR_NON_ACTIVE_WALLET[];

  static const char WITHDRAWAL_LIMIT_REACHED_FOR_DISPOSABLE_WALLET[];

  static const char SAVINGS_PERIOD_NOT_CONCLUDED_YET[];

  static const char INCORRECT_WALLET_TYPE[];

  static const char STANDARD_WALLET_COUNT_LIMIT_REACHED[];

  static const char WALLET_NOT_ASSOCIATED_WITH_THIS_USER[];
  static const char INCORRECT_WALLET_STATUS[];
  static const char NO_WALLET_FOUND_FOR_RECEIVER[];

  static const char TRANSFER_CRITERIA_NOT_MET[];
};
const char SystemErrors::INVALID_USERNAME[] =
    "Error: Invalid username, make sure the length is bigger than 4 and "
    "contains at least 1 digit.";
const char SystemErrors::INVALID_PASSWORD[] =
    "Error: Invalid password, make sure the length is exactly 6 and contains "
    "only digits.";
const char SystemErrors::USER_ALREADY_LOGGED_IN[] =
    "Error: User %s is already logged in.";
const char INCORRECT_LOGIN_CREDENTIALS[] =
    "Error: Incorrect username/password.";
const char SUCH_USERNAME_ALREADY_EXIST[] =
    "Error: Username %s is already in use.";
const char NO_ACTIVE_USER_SESSION_FOUND[] =
    "Error: No active user session found. Please log in first.";
const char INSUFFICIENT_FUNDS_IN_WALLET[] =
    "Error: Insufficient funds in wallet.";
const char NO_OPERATIONS_ALLOWED_FOR_NON_ACTIVE_WALLET[] =
    "Error: This wallet is non-active and cannot process transactions. No "
    "operations allowed for this wallet.";
const char WITHDRAWAL_LIMIT_REACHED_FOR_DISPOSABLE_WALLET[] =
    "Error: Withdrawal limit reached. This disposable wallet is now inactive "
    "and cannot process further transactions.";
const char SAVINGS_PERIOD_NOT_CONCLUDED_YET[] =
    "Error: Withdrawals are not permitted until the savings period has "
    "concluded. %d seconds left.";
const char INCORRECT_WALLET_TYPE[] =
    "Error: Invalid wallet type. Please choose from [Standard, Savings, "
    "Disposable].";
const char STANDARD_WALLET_COUNT_LIMIT_REACHED[] =
    "Error: Maximum limit of standard wallets reached. You are allowed to "
    "have only 1 standard wallets.";
const char WALLET_NOT_ASSOCIATED_WITH_THIS_USER[] =
    "Error: User %s is not associated with such wallet.";
const char INCORRECT_WALLET_STATUS[] =
    "Error: Invalid wallet status. Please choose from [ACTIVE, INACTIVE].";
const char NO_WALLET_FOUND_FOR_RECEIVER[] =
    "Error: Receiver %s has no Standard wallet. Can't initiate transfer.";
const char TRANSFER_CRITERIA_NOT_MET[] =
    "Error: You won't be able to initiate this transfer due to criteria not "
    "met.";
