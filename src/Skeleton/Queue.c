#include "Queue.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node* next;
  struct Node* prev;
  int data;
} Node;

struct Queue {
  Node* head;
  Node* tail;
  size_t size;
};
Queue* create_queue() {
  Queue* queue = malloc(sizeof(Queue));
  if (queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
  } else {
    fprintf(stderr, "Failed to allocate memory for queue\n");
    return NULL;
  }
  return queue;
}
void destroy_queue(Queue* queue) {
  if (queue) {
    Node* current = queue->head;
    while (current) {
      Node* temp = current;
      current = current->next;
      free(temp);
    }
    free(queue);
  } else {
    fprintf(stderr, "Failed to clean the queue\n");
  }
}
bool add(Queue* queue, int value) {
  Node* new_node = malloc(sizeof(Node));
  if (new_node) {
    queue->size++;
    new_node->data = value;
    new_node->next = NULL;
    if (!queue->head->next) {
      queue->head = new_node;
      queue->tail = new_node;
      new_node->prev = NULL;
    } else {
      new_node->prev = queue->tail;
      queue->tail = new_node;
      queue->tail->prev->next = new_node;
    }
  } else {
    fprintf(stderr, "Failed to allocate memory for new node\n");
    return false;
  }
  return true;
}
int remove_from_queue(Queue* queue) {
  if (queue) {
     if (get_size(queue) == 0) {
      fprintf(stderr, "We can't remove from the queue when empty\n");
      return INT_MIN;
    }
    Node* temp = queue->head;
  }
  return true;
}
bool is_empty(const Queue* queue) { get_size(queue) == 0; }
size_t get_size(const Queue* queue) { return queue->size; }
