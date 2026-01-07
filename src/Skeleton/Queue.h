#ifndef SRC_SKELETON_QUEUE_H_
#define SRC_SKELETON_QUEUE_H_
#include <stdbool.h>
#include <stddef.h>
typedef struct Queue Queue;
Queue* create_queue();
void destroy_queue(Queue* queue);
bool add(Queue* queue, int value);
bool remove_from_queue(Queue* queue, int* value);
bool is_queue_empty(const Queue* queue);
int queue_try_lock(Queue* queue);
void queue_unlock(Queue* queue);

size_t get_size(const Queue* queue);
#endif  // SRC_SKELETON_QUEUE_H_
