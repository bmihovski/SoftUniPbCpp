
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FilterInvalidCompanies(char* comp_data) {
  char* current_pos = comp_data;

  while (*current_pos != '\0') {
    // Parse company ID
    int comp_id = atoi(current_pos);

    if (comp_id == 0) {
      break;
    }

    // Skip to the company name (after the number and any whitespace)
    while (*current_pos != '\0' &&
           (isdigit(*current_pos) || isspace(*current_pos))) {
      current_pos++;
    }

    // Find the end of the company name (end of line)
    char* line_end = strchr(current_pos, '\n');
    if (line_end == NULL) {
      // Last line might not have newline
      line_end = current_pos + strlen(current_pos);
    }

    // Print valid companies (positive ID)
    if (comp_id > 0) {
      printf("%d ", comp_id);
      // Print company name
      while (current_pos < line_end) {
        putchar(*current_pos);
        current_pos++;
      }
      printf("\n");
    } else {
      // Skip this line for invalid companies
      current_pos = line_end;
    }

    // Move to next line
    if (*current_pos == '\n') {
      current_pos++;
    }
  }
}

int main() {
  char buff[1000] = {0};
  char line[256];

  while (fgets(line, sizeof(line), stdin) != NULL) {
    line[strcspn(line, "\n")] = '\0';
    if (strcmp(line, "end") == 0) {
      break;
    }
    strcat(buff, line);
    strcat(buff, "\n");
  }

  FilterInvalidCompanies(buff);
  return 0;
}
