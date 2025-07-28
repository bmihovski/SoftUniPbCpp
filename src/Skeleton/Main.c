#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buffer[1024];
  int line[1024];
  int counter = 0;
  if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
    return 1;
  }
  const char* token = strtok(buffer, " \n");
  while (token != nullptr) {
    int current = atoi(token);
    line[counter] = current;
    ++counter;
    token = strtok(nullptr, " \n");
  }

  size_t final_index = counter - 1;
  for (size_t start = 0; start < counter; ++start) {
    int to_display = 0;
    size_t last = final_index - start;
    if (start < last) {
      to_display = line[start] + line[last];
    } else {
      to_display = line[last];
    }
    printf("%d ", to_display);
  }
  printf("\n");
  return 0;
}
