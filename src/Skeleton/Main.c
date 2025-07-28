#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buffer[1024];
  int line[1024];
  int counter = 0;
  char* saveptr;
  if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
    return 1;
  }
  const char* token = strtok_r(buffer, " \n", &saveptr);
  while (token != nullptr) {
    int current = atoi(token);
    line[counter] = current;
    ++counter;
    token = strtok_r(nullptr, " \n", &saveptr);
  }

  size_t final_index = counter - 1;
  for (size_t start = 0; start < counter; ++start) {
    int to_display = 0;
    size_t last = final_index - start;
    if (start < last) {
      to_display = line[start] + line[last];
      printf("%d ", to_display);
    } else if (start == last) {
      to_display = line[last];
      printf("%d ", to_display);
    }
  }
  printf("\n");
  return 0;
}
