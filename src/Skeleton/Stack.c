#include "Stack.h"

#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node* prev;
} Node;

struct Stack {
  Node* head;
  size_t size;
  pthread_mutex_t mutex;
};

Stack* create_stack() {
  Stack* new_stack = (Stack*)malloc(sizeof(Stack));
  if (!new_stack) {
    return NULL;
  }
  new_stack->head = NULL;
  new_stack->size = 0;
  if (pthread_mutex_init(&new_stack->mutex, NULL) != 0) {
    free(new_stack);
    return NULL;
  }

  return new_stack;
}
void destroy_stack(Stack* stack) {
  if (!stack) {
    return;
  }
  pthread_mutex_lock(&stack->mutex);
  Node* current = stack->head;
  while (current) {
    Node* temp = current->prev;
    free(current);
    current = temp;
  }
  pthread_mutex_unlock(&stack->mutex);
  pthread_mutex_destroy(&stack->mutex);
  free(stack);
}
size_t stack_size(const Stack* stack) {
  if (!stack) {
    return 0;
  }
  pthread_mutex_lock((pthread_mutex_t*)&stack->mutex);
  size_t size = stack->size;
  pthread_mutex_unlock((pthread_mutex_t*)&stack->mutex);
  return size;
}
bool is_empty(const Stack* stack) {
  if (!stack) {
    return true;
  }
  pthread_mutex_lock((pthread_mutex_t*)&stack->mutex);
  bool result = (stack->size == 0);
  pthread_mutex_unlock((pthread_mutex_t*)&stack->mutex);
  return result;
}
bool push(Stack* stack, int data) {
  if (!stack) {
    return false;
  }
  Node* new_node = (Node*)malloc(sizeof(Node));
  if (!new_node) {
    return false;
  }
  new_node->data = data;
  pthread_mutex_lock(&stack->mutex);
  new_node->prev = stack->head;
  stack->head = new_node;
  stack->size++;
  pthread_mutex_unlock(&stack->mutex);
  return true;
}
bool pop(Stack* stack, int* output) {
  if (!stack) {
    return false;
  }
  pthread_mutex_lock(&stack->mutex);
  if (stack->size == 0) {
    pthread_mutex_unlock(&stack->mutex);
    return false;
  }
  Node* old_head = stack->head;
  *output = old_head->data;
  stack->head = stack->head->prev;
  stack->size--;
  pthread_mutex_unlock(&stack->mutex);
  free(old_head);
  return true;
}
bool peek(const Stack* stack, int* output) {
  if (!stack) {
    return false;
  }
  pthread_mutex_lock((pthread_mutex_t*)&stack->mutex);
  if (stack->size == 0) {
    pthread_mutex_unlock((pthread_mutex_t*)&stack->mutex);
    return false;
  }
  *output = stack->head->data;
  pthread_mutex_unlock((pthread_mutex_t*)&stack->mutex);
  return true;
}

Stack* copy_stack(Stack* source) {
  if (!source) {
    return NULL;
  }
  Stack* dest = create_stack();
  if (!dest) {
    destroy_stack(dest);
    return NULL;
  }
  Stack* backup = create_stack();
  if (!backup) {
    destroy_stack(backup);
    return NULL;
  }
  while (!is_empty(source)) {
    int current = 0;
    pop(source, &current);
    push(dest, current);
    push(backup, current);
  }
  while (!is_empty(backup)) {
    int temp = 0;
    pop(backup, &temp);
    push(source, temp);
  }
  destroy_stack(backup);
  return dest;
}

int stack_try_lock(Stack* stack) {
  if (!stack) {
    return -1;
  }
  return pthread_mutex_trylock(&stack->mutex);
}

void stack_unlock(Stack* stack) {
  if (!stack) {
    return;
  }
  pthread_mutex_unlock(&stack->mutex);
}
