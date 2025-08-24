#include "BankAccount.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
  char* user_name;
  char* account_number;
  double balance;
  // Method function pointers
  BankAccount_PrintFunc Print;
  BankAccount_GetBalanceFunc GetBalance;
  BankAccount_AddBalanceFunc AddBalance;
  BankAccount_WithdrawBalanceFunc WithdrawBalance;
  BankAccount_SetBalanceFunc SetBalance;
  BankAccount_DestroyFunc Destroy;
};

static bool IsBankAccountPresent(const BankAccount* account,
                                 const char* error_msg) {
  if (account == NULL || account->user_name == NULL ||
      account->account_number == NULL) {
    perror(error_msg);
    return false;
  }
  return true;
}

static double GetBalance_BankAccount_Impl(const BankAccount* account) {
  if (!IsBankAccountPresent(account, NOT_PRESENT_ACCOUNT_MSG)) {
    return .0;
  }
  return account->balance;
}

static void Print_BankAccount_Impl(const BankAccount* account) {
  if (!IsBankAccountPresent(account, NOT_PRESENT_ACCOUNT_MSG)) {
    return;
  }

  printf("Name : %s\n", account->user_name);
  printf("Account number : %s\n", account->account_number);
  printf("Balance : %.2lf\n", account->GetBalance(account));
}

static void AddBalance_BankAccount_Impl(BankAccount* account, double balance) {
  if (!IsBankAccountPresent(account, NOT_PRESENT_ACCOUNT_MSG) || balance <= 0) {
    printf("You can not add ZERO or Negative balance!\n");
    return;
  }
  account->balance += balance;
  return;
}

static void WithdrawnBalance_BankAccount_Impl(BankAccount* account,
                                              double amount) {
  if (!IsBankAccountPresent(account, NOT_PRESENT_ACCOUNT_MSG)) {
    return;
  }
  double updated_balance = account->balance - amount;
  if (amount <= 0 || updated_balance <= 0) {
    printf("You can not withdraw ZERO or Negative balance!\n");
    return;
  }
  account->balance = updated_balance;
  return;
}

static void SetInitialBalance_BankAccount_Impl(BankAccount* account,
                                               double balance) {
  if (!IsBankAccountPresent(account, NOT_PRESENT_ACCOUNT_MSG) && balance > 0) {
    return;
  }
  account->balance = balance;
  return;
}

void BankAccount_Destroy_Impl(BankAccount* account) {
  const char* error_msg =

      "Error: BankAccount_Destroy called with NULL account or invalid "
      "members.\n";
  if (!IsBankAccountPresent(account, error_msg)) {
    return;
  }
  free(account->user_name);
  free(account->account_number);
  free(account);
  return;
}

BankAccount* BankAccount_Create() {
  char user_name[MAX_BUFFER];
  char iban_code[MAX_IBAN_BUFFER];
  double Initial_balance = .0;
  BankAccount* account = (BankAccount*)malloc(sizeof(BankAccount));
  account->Print = Print_BankAccount_Impl;
  account->Destroy = BankAccount_Destroy_Impl;
  account->SetBalance = SetInitialBalance_BankAccount_Impl;
  account->GetBalance = GetBalance_BankAccount_Impl;
  account->WithdrawBalance = WithdrawnBalance_BankAccount_Impl;
  account->AddBalance = AddBalance_BankAccount_Impl;
  printf("Enter Name:\n");
  scanf(" %255s", user_name);
  printf("Enter 5 charactes IBAN Code:\n");
  scanf(" %5s", iban_code);
  printf("Enter Initial Balance:\n");
  scanf(" %lf", &Initial_balance);
  account->user_name = strdup(user_name);
  account->account_number = strdup(iban_code);
  account->SetBalance(account, Initial_balance);

  // Check if strdup failed
  const char* error_msg = "Failed to duplicate string";
  if (!IsBankAccountPresent(account, error_msg)) {
    return NULL;
  } else {
    return account;
  }
  return NULL;
}

void Print(const BankAccount* account) {
  account->Print(account);
  return;
}

void Destroy(BankAccount* account) {
  account->Destroy(account);
  return;
}

void SetInitialBalance(BankAccount* account, double balance) {
  account->SetBalance(account, balance);
  return;
}

double GetBalance(const BankAccount* account) {
  return account->GetBalance(account);
}

void WithdrawBalance(BankAccount* account, double balance) {
  account->WithdrawBalance(account, balance);
  return;
}

void AddBalance(BankAccount* account, double balance) {
  account->AddBalance(account, balance);
  return;
}
