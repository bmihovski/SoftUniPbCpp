// clang-format off
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
// clang-format on
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>

#include "Skeleton/Stack.h"

static int setup_tests(void** state) {
  Stack* stack = create_stack();
  if (!stack) {
    return -1;
  }
  *state = stack;
  return 0;
}

static int teardown_tests(void** state) {
  Stack* stack = (Stack*)*state;
  destroy_stack(stack);
  return 0;
}

static void test_stack_basic_operations(void** state) {
  Stack* list = (Stack*)*state;
  assert_non_null(list);
  push(list, 5);
  push(list, 7);
  push(list, 9);
  int result = 0;
  assert_true(pop(list, &result));
  assert_int_equal(result, 9);
  assert_uint_equal(stack_size(list), 2);
  assert_true(peek(list, &result));
  assert_int_equal(result, 7);
  assert_true(pop(list, &result));
  assert_int_equal(result, 7);
  assert_uint_equal(stack_size(list), 1);
  assert_true(pop(list, &result));
  assert_int_equal(result, 5);
  assert_uint_equal(stack_size(list), 0);
  assert_false(pop(list, &result));

  // Test adding after emptying
  push(list, 42);
  assert_uint_equal(stack_size(list), 1);
  assert_true(pop(list, &result));
  assert_int_equal(result, 42);
}

static void test_stack_empty(void** state) {
  Stack* s = (Stack*)*state;
  assert_non_null(s);
  assert_uint_equal(stack_size(s), 0);
  int dummy = 0;
  assert_false(pop(s, &dummy));
  assert_false(peek(s, &dummy));
}

static void test_multiple_insertion(void** state) {
  Stack* s = (Stack*)*state;
  for (int start = 0; start < 100; ++start) {
    push(s, start);
  }
  assert_int_equal(stack_size(s), 100);
  for (int expected = 99; expected >= 0; --expected) {
    int got;
    assert_true(pop(s, &got));
    assert_int_equal(got, expected);
  }
}

static void* try_lock_thread(void* arg) {
  Stack* stack = (Stack*)arg;
  int rc = stack_try_lock(stack);
  if (rc == 0) {
    stack_unlock(stack);
    return (void*)1; /* success */
  }
  return (void*)0; /* failed */
}

static void* thread_push(void* arg) {
  Stack* s = (Stack*)arg;
  for (int i = 0; i < 50; ++i) {
    push(s, i);
  }
  return NULL;
}

static void* thread_pop(void* arg) {
  Stack* stack = (Stack*)arg;
  for (int i = 0; i < 50; ++i) {
    int v;
    pop(stack, &v);
  }
  return NULL;
}

static void test_stack_mutex_unlock_after_push(void** state) {
  Stack* s = (Stack*)*state;
  assert_non_null(s);

  /* Lock the mutex manually to simulate a long‑running operation */
  stack_try_lock(s);
  /* Start a thread that will try to acquire the lock while we hold it */
  pthread_t t;
  int rc = pthread_create(&t, NULL, thread_push, s);
  assert_int_equal(rc, 0);
  /* Sleep a short time to give the thread a chance to run */
  struct timespec ts = {0, 1000000L};  // 1 ms
  nanosleep(&ts, NULL);

  /* Release the lock */
  stack_unlock(s);
  /* The thread should not have been able to lock yet */
  void* thread_result;
  pthread_join(t, &thread_result);
  assert_int_equal((intptr_t)thread_result, 0);

  assert_null(thread_pop(s));
}

static void test_stack_mutex_unlock_after_pop(void** state) {
  Stack* s = (Stack*)*state;
  assert_non_null(s);
  assert_null(thread_push(s));
  stack_try_lock(s);
  pthread_t thread;
  int rc = pthread_create(&thread, NULL, thread_pop, s);
  assert_int_equal(rc, 0);

  struct timespec st = {0, 1000000L};
  nanosleep(&st, NULL);

  stack_unlock(s);
  void* thread_result;
  pthread_join(thread, &thread_result);
  assert_int_equal((intptr_t)thread_result, 0);

  int value = 0;
  assert_false(pop(s, &value));
  assert_int_equal(value, 0);
  assert_true(is_empty(s));
}

static void test_when_queue_null_is_empty(void** state) {
  Stack* q = (Stack*)*state;
  assert_true(is_empty(NULL));
  assert_uint_equal(stack_size(NULL), 0);
  assert_false(pop(NULL, NULL));
  assert_false(peek(NULL, NULL));
  assert_false(push(NULL, 0));
  assert_false(copy_stack(NULL));
  assert_int_equal(stack_try_lock(NULL), -1);
}

static void test_destroy_stack_with_elements(void** state) {
  Stack* s = (Stack*)*state;
  assert_non_null(s);
  for (int i = 0; i < 10; ++i) {
    push(s, i);
  }
  destroy_stack(s);
  *state = NULL;
}

static void test_stack_unlock_allows_operations(void** state) {
  Stack* s = (Stack*)*state;
  stack_try_lock(s);
  stack_unlock(s);
  push(s, 5);
  int value = 0;
  assert_true(pop(s, &value));
  assert_int_equal(value, 5);
}

static void test_stack_unlock_null_safe(void** state) {
  (void)state;
  stack_unlock(NULL);
  assert_true(true);
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test_setup_teardown(test_stack_basic_operations, setup_tests,
                                      teardown_tests),
      cmocka_unit_test_setup_teardown(test_stack_empty, setup_tests,
                                      teardown_tests),
      cmocka_unit_test_setup_teardown(test_multiple_insertion, setup_tests,
                                      teardown_tests),
      cmocka_unit_test_setup_teardown(test_stack_mutex_unlock_after_push,
                                      setup_tests, teardown_tests),
      cmocka_unit_test_setup_teardown(test_stack_mutex_unlock_after_pop,
                                      setup_tests, teardown_tests),
      cmocka_unit_test_setup_teardown(test_when_queue_null_is_empty,
                                      setup_tests, teardown_tests),
      cmocka_unit_test_setup_teardown(test_destroy_stack_with_elements,
                                      setup_tests, teardown_tests),
      cmocka_unit_test_setup_teardown(test_stack_unlock_null_safe, setup_tests,
                                      teardown_tests),
      cmocka_unit_test_setup_teardown(test_stack_unlock_allows_operations,
                                      setup_tests, teardown_tests),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
