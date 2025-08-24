#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BankAccount.h"
void PrintMenu() {
  printf("Would you like to do ?\n");
  printf("Press 1 to Show All Information...\n");
  printf("Press 2 to Add Balance...\n");
  printf("Press 3 to Withdraw Balance...\n");
  printf("Press 0 to Exit Program...\n");
}
int main() {
  BankAccount* bank_account = BankAccount_Create();
  while (1) {
    PrintMenu();
    int user_option = 0;
    if (scanf(" %d", &user_option) != 1) {
      return 1;
    }
    switch (user_option) {
      case 1:

        Print(bank_account);
        continue;
      case 2:
        printf("Enter Balance to Add:\n");
        double amount = 0.0;
        if (scanf(" %lf", &amount) != 1) {
          printf("Invalid input for amount.\n");
          continue;
        }
        AddBalance(bank_account, amount);
        continue;
      case 3:
        printf("Enter Balance to Withdraw:\n");
        double withdrawn_amount = 0.0;
        if (scanf(" %lf", &withdrawn_amount) != 1) {
          printf("Invalid amount to Withdraw.\n");
          continue;
        }
        WithdrawBalance(bank_account, withdrawn_amount);
        continue;
      case 0:
        Destroy(bank_account);
        return 0;
      default:
        printf("Invalid option, please try again.\n");
        break;
    }
  }

  return 0;
}
