#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#define NOT_PRESENT_ACCOUNT_MSG "Account is missing"
#define MAX_BUFFER 256
#define MAX_IBAN_BUFFER 6

typedef struct BankAccount BankAccount;
// Function pointer types for better type safety
typedef void (*BankAccount_PrintFunc)(const BankAccount*);
typedef double (*BankAccount_GetBalanceFunc)(const BankAccount*);
typedef void (*BankAccount_AddBalanceFunc)(BankAccount*, double);
typedef void (*BankAccount_WithdrawBalanceFunc)(BankAccount*, double);
typedef void (*BankAccount_SetBalanceFunc)(BankAccount*, double);
typedef void (*BankAccount_DestroyFunc)(BankAccount*);
/**
 * @brief Prints the details of a bank account.
 *
 * @param account A pointer to the BankAccount to print.
 */
void Print(const BankAccount* account);
/** @brief Gets the balance of a bank account.
 *
 * @param account A pointer to the BankAccount.
 * @return The balance of the account.
 */
double GetBalance(const BankAccount* account);
/**
 * @brief Adds funds to a bank account.
 *
 * @param account A pointer to the BankAccount.
 * @param amount The amount to add.
 */
void AddBalance(BankAccount* account, double balance);
/**
 * @brief Withdraws funds from a bank account.
 *
 * @param account A pointer to the BankAccount.
 * @param amount The amount to withdraw.
 */
void WithdrawBalance(BankAccount* account, double balance);
/**
 * @brief Sets the initial balance of a bank account.
 *
 * @param account A pointer to the BankAccount.
 * @param balance The initial balance.
 */
void SetInitialBalance(BankAccount* account, double balance);
/** @brief Destroys a bank account and frees its memory.
 *
 * @param account A pointer to the BankAccount to destroy.
 */
void Destroy(BankAccount* balance);

/**
 * @brief Creates a new bank account.
 *
 * @return A pointer to the newly created BankAccount.
 */
BankAccount* BankAccount_Create();

#endif  // BANK_ACCOUNT_H
