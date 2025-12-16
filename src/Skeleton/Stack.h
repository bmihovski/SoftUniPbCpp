#ifndef SRC_SKELETON_STACK_H_
#define SRC_SKELETON_STACK_H_
#include <stddef.h>
typedef struct Stack Stack;
Stack* create_stack();
void destroy_stack(Stack* stack);
bool is_empty(const Stack* stack);
void push(Stack* stack, int data);
int pop(Stack* stack);
int peek(const Stack* stack);
size_t stack_size(const Stack* stack);
#endif  // SRC_SKELETON_STACK_H_
