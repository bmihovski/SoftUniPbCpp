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

static void test_stack_basic_operations(void** state) {
  (void)state;
  Stack* list = create_stack();
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
  destroy_stack(list);
}

static void test_stack_empty(void** state) {
  (void)state;
  Stack* s = create_stack();
  assert_non_null(s);
  assert_uint_equal(stack_size(s), 0);
  int dummy = 0;
  assert_false(pop(s, &dummy));
  assert_false(peek(s, &dummy));
  destroy_stack(s);
}

static void test_multiple_insertion(void** state) {
  (void)state; /* unused */
  Stack* s = create_stack();
  for (int start = 0; start < 100; ++start) {
    push(s, start);
  }
  assert_int_equal(stack_size(s), 100);
  for (int expected = 99; expected >= 0; --expected) {
    int got;
    assert_true(pop(s, &got));
    assert_int_equal(got, expected);
  }
  destroy_stack(s);
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
  (void)state;
  Stack* s = create_stack();
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

  destroy_stack(s);
}

static void test_stack_mutex_unlock_after_pop(void** state) {
  (void)state;
  Stack* s = create_stack();
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
  destroy_stack(s);
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_stack_basic_operations),
      cmocka_unit_test(test_stack_empty),
      cmocka_unit_test(test_multiple_insertion),
      cmocka_unit_test(test_stack_mutex_unlock_after_push),
      cmocka_unit_test(test_stack_mutex_unlock_after_pop),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
