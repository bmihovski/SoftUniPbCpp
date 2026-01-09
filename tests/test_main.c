// clang-format off
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
// clang-format on
#include <stdio.h>
#include <stdlib.h>
#define TEST_INPUT_FILE "/tmp/test_input.txt"
#define TEST_OUTPUT_FILE "/tmp/test_output.txt"

int mainPoint(void);

static char* run_program_with_input(const char* input) {
  FILE* fin = fopen(TEST_INPUT_FILE, "w");
  fputs(input, fin);
  fclose(fin);
  FILE* old_stdin = stdin;
  FILE* old_stdout = stdout;
  stdin = fopen(TEST_INPUT_FILE, "r");
  stdout = fopen(TEST_OUTPUT_FILE, "w");

  int ret = mainPoint();
  (void)ret;
  fclose(stdin);
  fclose(stdout);
  stdin = old_stdin;
  stdout = old_stdout;

  FILE* fout = fopen(TEST_OUTPUT_FILE, "r");
  fseek(fout, 0, SEEK_END);
  long size = ftell(fout);
  fseek(fout, 0, SEEK_SET);

  char* output = malloc(size + 1);
  fread(output, 1, size, fout);
  output[size] = '\0';
  fclose(fout);
  return output;
}

static void test_push_and_print(void** state) {
  (void)state;
  const char* input = "4\n1 10\n1 20\n3\n3\n";
  char* output = run_program_with_input(input);

  assert_string_equal(output, "20\n20\n20, 10\n\n");
  free(output);
}

static void test_push_pop_sequence(void** state) {
  (void)state;
  const char* input = "5\n1 5\n1 15\n2\n1 8\n3\n";
  char* output = run_program_with_input(input);

  assert_string_equal(output, "8\n8, 5\n\n");
  free(output);
}

static void test_min_max_operations(void** state) {
  (void)state;
  const char* input = "5\n1 100\n1 50\n1 75\n3\n4\n";
  char* output = run_program_with_input(input);

  assert_string_equal(output, "100\n50\n75, 50, 100\n\n");
  free(output);
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_push_and_print),
      cmocka_unit_test(test_push_pop_sequence),
      cmocka_unit_test(test_min_max_operations),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
