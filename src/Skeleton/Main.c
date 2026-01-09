#include <ctype.h>
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_LOCK(q) pthread_mutex_lock(&(q)->lock)
#define QUEUE_UNLOCK(q) pthread_mutex_unlock(&(q)->lock)

typedef struct NodeQueue {
  struct NodeQueue* next;
  struct NodeQueue* prev;
  int data;
} NodeQueue;

typedef struct Queue {
  NodeQueue* head;
  NodeQueue* tail;
  size_t size;
  pthread_mutex_t lock;
} Queue;
Queue* create_queue() {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  if (!queue) {
    fprintf(stderr, "Failed to allocate memory for queue\n");
    return NULL;
  }
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  if (pthread_mutex_init(&queue->lock, NULL) != 0) {
    fprintf(stderr, "Failed to initialise mutex\n");
    free(queue);
    return NULL;
  }
  return queue;
}
void destroy_queue(Queue* queue) {
  if (!queue) {
    fprintf(stderr, "Failed to clean the queue\n");
    return;
  }
  QUEUE_LOCK(queue);
  NodeQueue* current = queue->head;
  while (current) {
    NodeQueue* temp = current;
    current = current->next;
    free(temp);
  }
  queue->size = 0;
  QUEUE_UNLOCK(queue);
  pthread_mutex_destroy(&queue->lock);
  free(queue);
}

bool add(Queue* queue, int value) {
  if (!queue) {
    return false;
  }
  NodeQueue* new_node = (NodeQueue*)malloc(sizeof(NodeQueue));
  if (!new_node) {
    fprintf(stderr, "Failed to allocate memory for new node\n");
    return false;
  }
  QUEUE_LOCK(queue);
  new_node->data = value;
  new_node->next = NULL;
  new_node->prev = queue->tail;
  if (!queue->head) {
    queue->head = new_node;
    queue->tail = new_node;
  } else {
    queue->tail->next = new_node;
    queue->tail = new_node;
  }
  queue->size++;
  QUEUE_UNLOCK(queue);
  return true;
}

size_t get_size(const Queue* queue) {
  if (!queue) {
    return 0;
  }

  return queue->size;
}

bool remove_from_queue(Queue* queue, int* value) {
  if (!queue) {
    fprintf(stderr, "Cannot remove from an empty queue\n");
    return false;
  }
  QUEUE_LOCK(queue);
  if (get_size(queue) == 0) {
    fprintf(stderr, "We can't remove from the queue when empty\n");
    QUEUE_UNLOCK(queue);
    return false;
  }
  NodeQueue* temp = queue->head;
  int value_to_remove = temp->data;
  if (get_size(queue) == 1) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
  } else {
    queue->head = queue->head->next;
    if (queue->head) queue->head->prev = NULL;
    queue->size--;
  }
  free(temp);
  QUEUE_UNLOCK(queue);
  *value = value_to_remove;
  return true;
}

int queue_try_lock(Queue* queue) {
  if (!queue) {
    return -1;
  }
  return pthread_mutex_lock(&queue->lock);
}

void queue_unlock(Queue* queue) {
  if (!queue) {
    return;
  }
  pthread_mutex_unlock(&queue->lock);
}
bool is_queue_empty(const Queue* queue) {
  if (!queue) {
    return true;
  }
  QUEUE_LOCK((Queue*)queue);
  bool is_empty = (get_size(queue) == 0);
  QUEUE_UNLOCK((Queue*)queue);
  return is_empty;
}
typedef struct Node {
  int data;
  struct Node* prev;
} Node;

typedef struct Stack {
  Node* head;
  size_t size;
  pthread_mutex_t mutex;
} Stack;

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

enum QueryType { PUSH = 1, DELETE, PRINT_MAX, PRINT_MIN };
int mainPoint() {
  FilterFunc func_filt;
  int num_operations = 0;
  int value_to_push = 0;
  int result = 0;
  scanf("%d", &num_operations);
  Stack* new_stack = create_stack();
  bool (*filter)(int value);
  while ((num_operations--) != 0) {
    enum QueryType current_operation;
    scanf("%d", (int*)&current_operation);
    switch (current_operation) {
      case PUSH:
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

int main() {
  return mainPoint();
}
