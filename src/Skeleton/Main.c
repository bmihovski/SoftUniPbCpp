#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

typedef struct {
  char **firtered_words;
  int count;
} WordList;

void FilterPunctuation(char *token) {
  char *dst = token;
  for (char *src = token; *src; src++) {
    if (isalpha(*src)) {
      *dst++ = *src;
    }
  }
  *dst = '\0';
}

void AddWord(WordList *list, const char *word) {
  for (int start = 0; start < list->count; ++start) {
    if (strcmp(list->firtered_words[start], word) == 0) {
      return;
    }
  }
  list->firtered_words = (char **)realloc(list->firtered_words,
                                          (list->count + 1) * sizeof(char *));
  list->firtered_words[list->count] = strdup(word);
  list->count++;
}

bool AddMatches(const char symbol, const char *words, WordList *matches) {
  const char ctr_sym_lower = tolower(symbol);
  char temp_buf[MAX_BUFFER_SIZE];
  strcpy(temp_buf, words);
  char *temp = temp_buf;
  char *token = strtok_r(temp, " \n\t\b", &temp);
  while (token != NULL) {
    FilterPunctuation(token);
    if (strlen(token) > 0) {
      char const *temp_token = token;
      size_t count = 0;
      bool is_valid = false;
      while (isalpha(temp_token[count])) {
        if (ctr_sym_lower == tolower(temp_token[count])) {
          is_valid = true;

          break;
        }
        count++;
      }

      if (is_valid) {
        AddWord(matches, token);
      }
    }

    token = strtok_r(NULL, " \n\t\b", &temp);
  }

  return matches->count != 0;
}

int SortWords(const void *first, const void *second) {
  char **first_word = (char **)first;
  char **second_word = (char **)second;
  return strcmp(*first_word, *second_word);
}

void FreeMemory(WordList *matches) {
  for (int i = 0; i < matches->count; i++) {
    free(matches->firtered_words[i]);
  }
  free(matches->firtered_words);
}

int main() {
  char *buffer = NULL;
  size_t buffer_size = 0;
  char contr_char = 0;
  if (getline(&buffer, &buffer_size, stdin) == -1) {
    perror("getline");
    free(buffer);
    return 1;
  }

  if (buffer == NULL) {
    perror("Buffer is NULL");
    return 1;
  }

  while (scanf(" %c", &contr_char) && contr_char != '.') {
    WordList matches = {NULL, 0};
    size_t total_matches = 0;
    bool are_matches = false;
    are_matches = AddMatches(contr_char, buffer, &matches);
    if (!are_matches) {
      printf("---\n");
    } else {
      qsort(matches.firtered_words, matches.count, sizeof(char *), SortWords);
      for (int start = 0; start < matches.count; start++) {
        printf("%s ", matches.firtered_words[start]);
      }
      printf("\n");
    }
    FreeMemory(&matches);
  }
  free(buffer);
  return 0;
}
