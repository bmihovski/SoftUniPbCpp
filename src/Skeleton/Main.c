
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX_WORDS 1000

int WordsCompare(const void *a, const void *b) {
  const char *s1 = *(const char **)a;
  const char *s2 = *(const char **)b;
  return strcmp(s1, s2);
}

int RemoveDuplicates(char *words[], size_t match_count) {
  if (match_count <= 1) {
    return match_count;
  }
  size_t temp_match = 0;
  for (int i = 0; i < match_count; ++i) {
    if (strcmp(words[i], words[temp_match]) != 0) {
      words[++temp_match] = words[i];
    }
  }
  return temp_match + 1;
}

int ContainsLetter(const char *word, char letter) {
  char match = tolower(letter);
  for (size_t start = 0; word[start]; ++start) {
    if (tolower(word[start]) == match) {
      return 1;
    }
  }
  return 0;
}

int main() {
  char text[1000];
  char *words[MAX_WORDS];
  int word_count = 0;
  if (fgets(text, sizeof(text), stdin) == NULL) {
    return 1;
  }

  char *token = strtok(text, " \t\n\r.,;!?");
  while (token != NULL && word_count < MAX_WORDS) {
    // Copy the token to avoid modifying the original
    words[word_count] = (char *)malloc(strlen(token) + 1);
    strcpy(words[word_count], token);
    word_count++;
    token = strtok(NULL, " \t\n\r.,;!?");
  }

  char letter = 0;
  while (1) {
    scanf(" %c", &letter);
    if (letter == '.') {
      break;
    }
    char *matches[MAX_WORDS];
    size_t match_count = 0;
    for (int i = 0; i < word_count; ++i) {
      if (ContainsLetter(words[i], letter)) {
        matches[match_count++] = words[i];
      }
    }

    qsort(matches, match_count, sizeof(char *), WordsCompare);

    match_count = RemoveDuplicates(matches, match_count);
    if (match_count == 0) {
      printf("---\n");
    } else {
      for (size_t start = 0; start < match_count; ++start) {
        printf("%s ", matches[start]);
      }
      printf("\n");
    }
  }

  for (size_t row = 0; row < word_count; ++row) {
    free(words[row]);
  }

  return 0;
}
