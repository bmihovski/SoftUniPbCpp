#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Stack.h"

enum QueryType { PUSH = 1, DELETE, PRINT_MAX, PRINT_MIN };
typedef void (*FilterFunc)(int, int*);

void print_filtered(Stack* current_stack, FilterFunc filter,
                    int initial_value) {
  Stack* copy = copy_stack(current_stack);
  int value_to_find = initial_value;
  while (!is_empty(copy)) {
    int current = 0;
    pop(copy, &current);
    filter(current, &value_to_find);
  }
  if (value_to_find != initial_value) {
    printf("%d\n", value_to_find);
  }
  destroy_stack(copy);
}

void min_val(int current, int* result) {
  if (current < *result) {
    *result = current;
  }
}

void max_val(int current, int* result) {
  if (current > *result) {
    *result = current;
  }
}

int main_program() {
  FilterFunc func_filt;
  int num_operations = 0;
  scanf("%d", &num_operations);
  Stack* new_stack = create_stack();
  bool (*filter)(int value);
  while ((num_operations--) != 0) {
    enum QueryType current_operation;
    scanf("%d", &current_operation);
    switch (current_operation) {
      case PUSH:
        int value_to_push = 0;
        scanf("%d", &value_to_push);
        push(new_stack, value_to_push);
        break;
      case PRINT_MAX:
        if (!is_empty(new_stack)) {
          func_filt = max_val;
          print_filtered(new_stack, func_filt, INT_MIN);
        }
        break;
      case PRINT_MIN:
        func_filt = min_val;
        print_filtered(new_stack, func_filt, INT_MAX);
        break;
      case DELETE:
        int result = 0;
        pop(new_stack, &result);
        break;
      default:
        destroy_stack(new_stack);
        return 1;
    }
  }
  bool is_first = true;
  while (!is_empty(new_stack)) {
    if (!is_first) {
      printf(", ");
    } else {
      is_first = false;
    }
    int result = 0;
    if (!pop(new_stack, &result)) {
      return 1;
    }
    printf("%d", result);
  }
  puts("\n");
  destroy_stack(new_stack);
  return 0;
}

