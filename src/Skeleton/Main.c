#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTITION 100

typedef struct {
  size_t count;
  int from;
  int to;
} Range;

Range* create_range(int from, int to, size_t count) {
  Range* range = (Range*)malloc(sizeof(Range));
  range->count = count;
  range->from = from;
  range->to = to;
  return range;
}

void create_partition(Range** ranges, size_t* start, size_t* end,
                      const int num) {
  if (*start >= *end) {
    return;
  }
  const size_t mid = *start + (*end - *start) / 2;
  if (num >= ranges[mid]->from) {
    *start = ranges[mid]->count;
  } else {
    *end = ranges[mid]->count;
  }
  return;
}

bool is_in_range(Range** ranges, size_t ranges_count, const int num_to_check) {
  const Range* start_range = ranges[0];
  const Range* end_range = ranges[ranges_count - 1];
  size_t start_index = start_range->count;
  size_t end_index = end_range->count;
  if (num_to_check < start_range->from || num_to_check > end_range->to) {
    return false;
  }
  while ((end_index - start_index) >= MAX_PARTITION) {
    create_partition(ranges, &start_index, &end_index, num_to_check);
  }
  for (size_t start = start_index; start <= end_index; ++start) {
    if (num_to_check >= ranges[start]->from &&
        num_to_check <= ranges[start]->to) {
      return true;
    }
  }

  return false;
}

int main() {
  int from = 0;
  int to = 0;
  Range** ranges = (Range**)malloc(sizeof(Range*) * 10000);
  size_t ranges_count = 0;
  while (1) {
    if (scanf(" %d %d", &from, &to) != 2) {
      break;
    }
    Range* range = create_range(from, to, ranges_count);
    ranges[ranges_count++] = range;
  }
  int c = 0;
  while ((c = getchar()) != EOF && c != '\n');
  int num = 0;
  while (1) {
    // Peek at the next character
    int peek_char = getchar();
    if (peek_char == '.') {
      break;  // Break if '.' is encountered
    }

    // Put the character back and read as number
    ungetc(peek_char, stdin);
    if (scanf(" %d", &num) != 1) {
      break;
    }

    bool found = is_in_range(ranges, ranges_count, num);
    if (found) {
      printf("in\n");
    } else {
      printf("out\n");
    }
  }

  for (size_t i = 0; i < ranges_count; i++) {
    free(ranges[i]);
  }
  free(ranges);

  return 0;
}
