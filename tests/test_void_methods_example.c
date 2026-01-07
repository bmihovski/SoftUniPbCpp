// clang-format off
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
// clang-format on
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Example 1: Simple void function that modifies state
typedef struct {
  int value;
  char* buffer;
} ExampleStruct;

void init_struct(ExampleStruct* s, int value) {
  if (!s) return;
  s->value = value;
  s->buffer = malloc(100);
  if (s->buffer) {
    strcpy(s->buffer, "initialized");
  }
}

void cleanup_struct(ExampleStruct* s) {
  if (!s) return;
  free(s->buffer);
  s->buffer = NULL;
  s->value = 0;
}

// Example 2: Void function that calls another function (for mocking)
typedef void (*log_func)(const char*);
static log_func current_logger = NULL;

void set_logger(log_func logger) { current_logger = logger; }

void log_message(const char* msg) {
  if (current_logger) {
    current_logger(msg);
  }
}

void process_with_logging(int value) {
  if (value < 0) {
    log_message("Negative value detected");
  } else if (value == 0) {
    log_message("Zero value");
  }
  // Do some processing...
}

// Mock logger for testing
static int mock_log_call_count = 0;
static char last_log_message[256];

static void mock_logger(const char* msg) {
  mock_log_call_count++;
  strncpy(last_log_message, msg, sizeof(last_log_message) - 1);
  last_log_message[sizeof(last_log_message) - 1] = '\0';
  // You can also use check_expected() if using expect_string()
}

// ==================== TESTS ====================

// Test 1: Testing void method by verifying state changes
static void test_init_struct(void** state) {
  (void)state;

  ExampleStruct s;
  memset(&s, 0, sizeof(s));

  // Call void method
  init_struct(&s, 42);

  // Verify state changes
  assert_int_equal(s.value, 42);
  assert_non_null(s.buffer);
  assert_string_equal(s.buffer, "initialized");

  // Cleanup
  cleanup_struct(&s);
  assert_null(s.buffer);
  assert_int_equal(s.value, 0);
}

// Test 2: Testing void method with NULL parameter
static void test_init_struct_null(void** state) {
  (void)state;

  // This should not crash
  init_struct(NULL, 42);

  // Also test cleanup with NULL
  cleanup_struct(NULL);

  // If we get here without crashing, test passes
  assert_true(1);
}

// Test 3: Testing void method that calls mocked function
static void test_process_with_logging_negative(void** state) {
  (void)state;

  // Setup mock
  mock_log_call_count = 0;
  last_log_message[0] = '\0';
  set_logger(mock_logger);

  // Call void method
  process_with_logging(-5);

  // Verify mock was called
  assert_int_equal(mock_log_call_count, 1);
  assert_string_equal(last_log_message, "Negative value detected");
}

static void test_process_with_logging_zero(void** state) {
  (void)state;

  mock_log_call_count = 0;
  last_log_message[0] = '\0';
  set_logger(mock_logger);

  process_with_logging(0);

  assert_int_equal(mock_log_call_count, 1);
  assert_string_equal(last_log_message, "Zero value");
}

static void test_process_with_logging_positive(void** state) {
  (void)state;

  mock_log_call_count = 0;
  last_log_message[0] = '\0';
  set_logger(mock_logger);

  process_with_logging(10);

  // Should not call logger for positive values
  assert_int_equal(mock_log_call_count, 0);
}

// Test 4: Using CMocka's expect/check mechanism (more advanced)
static void mock_logger_with_check(const char* msg) {
  // Check that the parameter matches what we expected
  check_expected(msg);
}

static void test_process_with_expect_check(void** state) {
  (void)state;

  set_logger(mock_logger_with_check);

  // Expect the logger to be called with "Negative value detected"
  expect_string(mock_logger_with_check, msg, "Negative value detected");

  // This will trigger check_expected() inside mock_logger_with_check
  process_with_logging(-3);
}

// Test 5: Testing memory allocation in void method
static void test_init_struct_memory_failure(void** state) {
  (void)state;

  // We can't easily test malloc failure without mocking malloc,
  // but we can test that the function handles it gracefully
  ExampleStruct s;
  memset(&s, 0, sizeof(s));

  // In a real test, you might use a custom allocator or
  // set malloc to fail using will_return()
  init_struct(&s, 99);

  // The function should either handle malloc failure gracefully
  // or we assume malloc succeeds in normal conditions
  if (s.buffer) {
    assert_string_equal(s.buffer, "initialized");
    cleanup_struct(&s);
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_init_struct),
      cmocka_unit_test(test_init_struct_null),
      cmocka_unit_test(test_process_with_logging_negative),
      cmocka_unit_test(test_process_with_logging_zero),
      cmocka_unit_test(test_process_with_logging_positive),
      cmocka_unit_test(test_process_with_expect_check),
      cmocka_unit_test(test_init_struct_memory_failure),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
