
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main() {
  char *line = NULL;
  size_t len_line = 0;
  size_t matr_len = 0;
  int sum_numbers = 0;

  scanf("%ld", &matr_len);
  while (getchar() != '\n');
  int **matr = (int **)malloc(matr_len * sizeof(int *));
  ssize_t read = getline(&line, &len_line, stdin);
  if (read == -1) {
    free(line);
    free(matr);
    return 1;
  } else {
    line[read - 1] = '\0';
  }
  for (size_t row = 0; row < matr_len; ++row) {
    matr[row] = (int *)malloc(matr_len * sizeof(int));
  }

  char *token = strtok(line, " ");
  for (size_t row = 0; row < matr_len; ++row) {
    for (size_t col = 0; col < matr_len; ++col) {
      if (token == NULL) {
        break;
      }
      matr[row][col] = atoi(token);
      token = strtok(NULL, " ");
    }
  }

  for (size_t row = 0; row < matr_len; ++row) {
    for (size_t col = 0; col < matr_len; ++col) {
      if (row == col || row + col == matr_len - 1) {
        continue;
      }
      int current_num = matr[row][col];
      if (current_num % 2 != 0) {
        sum_numbers += current_num;
      }
    }
  }

  printf("The sum is: %d\n", sum_numbers);

  for (size_t row = 0; row < matr_len; ++row) {
    free(matr[row]);
  }

  free(matr);
  free(line);

  return 0;
}
