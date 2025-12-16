#include "Stack.h"

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node* prev;
} Node;

struct Stack {
  Node* head;
  size_t size;
};

Stack* create_stack() {
  Stack* new_stack = (Stack*)malloc(sizeof(Stack));
  if (!new_stack) {
    return NULL;
  }
  new_stack->head = NULL;
  new_stack->size = 0;

  return new_stack;
}
void destroy_stack(Stack* stack) {
  if (stack) {
    return;
  }
  Node* current = stack->head;
  while (current) {
    Node* temp = current->prev;
    free(current);
    current = temp;
  }
  free(stack);
}
size_t stack_size(const Stack* stack) { return stack->size; }
bool is_empty(const Stack* stack) { return stack_size(stack) == 0; }
void push(Stack* stack, int data) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  if (!new_node) {
    return;
  }
  new_node->data = data;
  new_node->prev = stack->head;
  stack->head = new_node;
  stack->size++;
}
int pop(Stack* stack) {
  if (is_empty(stack)) {
    return INT_MIN;
  }
  stack->size--;
  Node* old_head = stack->head;
  int result = old_head->data;
  stack->head = stack->head->prev;
  free(old_head);
  return result;
}
int peek(const Stack* stack) {
  if (is_empty(stack)) {
    return INT_MIN;
  }
  return stack->head->data;
}
