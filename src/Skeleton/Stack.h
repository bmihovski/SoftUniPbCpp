#ifndef SRC_SKELETON_STACK_H_
#define SRC_SKELETON_STACK_H_
#include <stddef.h>
typedef struct Stack Stack;
Stack* create_stack();
void destroy_stack(Stack* stack);
bool is_empty(const Stack* stack);
void push(Stack* stack, int data);
bool pop(Stack* stack, int* output);
bool peek(const Stack* stack, int* output);
size_t stack_size(const Stack* stack);
Stack* copy_stack(Stack* source);
int stack_try_lock(Stack* stack);
void stack_unlock(Stack* stack);
#endif  // SRC_SKELETON_STACK_H_
