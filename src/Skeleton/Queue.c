#include "Queue.h"

#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_LOCK(q) pthread_mutex_lock(&(q)->lock)
#define QUEUE_UNLOCK(q) pthread_mutex_unlock(&(q)->lock)

typedef struct Node {
  struct Node* next;
  struct Node* prev;
  int data;
} Node;

struct Queue {
  Node* head;
  Node* tail;
  size_t size;
  pthread_mutex_t lock;
};
Queue* create_queue() {
  Queue* queue = malloc(sizeof(Queue));
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
  Node* current = queue->head;
  while (current) {
    Node* temp = current;
    current = current->next;
    free(temp);
  }
  queue->size = 0;
  QUEUE_UNLOCK(queue);
  pthread_mutex_destroy(&queue->lock);
  free(queue);
}

bool add(Queue* queue, int value) {
  Node* new_node = malloc(sizeof(Node));
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

int remove_from_queue(Queue* queue) {
  if (!queue) {
    fprintf(stderr, "Cannot remove from an empty queue\n");
    return INT_MIN;
  }
  QUEUE_LOCK(queue);
  if (get_size(queue) == 0) {
    fprintf(stderr, "We can't remove from the queue when empty\n");
    QUEUE_UNLOCK(queue);
    return INT_MIN;
  }
  Node* temp = queue->head;
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
  return value_to_remove;
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
size_t get_size(const Queue* queue) {
  if (!queue) {
    return 0;
  }

  return queue->size;
}
