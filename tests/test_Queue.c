
// clang-format off
#include <_time.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>
// clang-format on
#include "Skeleton/Queue.h"

static int setup(void** state) {
  Queue* q = create_queue();
  if (!q) {
    return -1;
  }
  *state = q;
  return 0;
}

static int tear_down(void** state) {
  Queue* q = (Queue*)*state;
  destroy_queue(q);
  return 0;
}

static void test_queue_basic_operations(void** state) {
  Queue* queue = (Queue*)*state;
  assert_true(add(queue, 42));
  assert_int_equal(get_size(queue), 1);
  assert_false(is_queue_empty(queue));
  int value = 0;
  assert_true(remove_from_queue(queue, &value));
  assert_int_equal(value, 42);
  assert_int_equal(get_size(queue), 0);
  assert_true(is_queue_empty(queue));
  assert_true(add(queue, 5));
  destroy_queue(queue);
  *state = create_queue();
}

static void test_element_from_empty_queue_can_not_be_removed(void** state) {
  Queue* queue = (Queue*)*state;
  int dummy = 0;
  assert_false(remove_from_queue(queue, &dummy));
  assert_true(is_queue_empty(queue));
}

static void test_add_and_remove_mulitple_elements(void** state) {
  Queue* q = (Queue*)*state;
  assert_true(add(q, 42));
  assert_true(add(q, 1));
  assert_false(is_queue_empty(q));
  assert_int_equal(get_size(q), 2);
  int temp = 0;
  assert_true(remove_from_queue(q, &temp));
  assert_int_equal(temp, 42);
  assert_int_equal(get_size(q), 1);
  assert_false(is_queue_empty(q));
  assert_true(remove_from_queue(q, &temp));
  assert_int_equal(temp, 1);
  assert_int_equal(get_size(q), 0);
  assert_true(is_queue_empty(q));
  assert_true(is_queue_empty(NULL));
  assert_false(remove_from_queue(NULL, &temp));
  destroy_queue(NULL);
}

static void* add_multi_elems(void* arg) {
  Queue* q = (Queue*)arg;
  for (int start = 0; start < 50; ++start) {
    add(q, start);
  }

  return NULL;
}

static void* remove_multiple_elems(void* arg) {
  Queue* q = (Queue*)arg;
  for (int i = 0; i < 50; ++i) {
    int val;
    remove_from_queue(q, &val);
  }
  return NULL;
}

static void test_mutex_unlock_after_push(void** state) {
  Queue* q = (Queue*)*state;
  queue_try_lock(q);
  pthread_t tid;
  int rc = pthread_create(&tid, NULL, add_multi_elems, q);
  assert_int_equal(rc, 0);

  struct timespec ts = {0, 1000000L};
  nanosleep(&ts, NULL);
  queue_unlock(q);
  void* thread_result;
  pthread_join(tid, &thread_result);
  assert_int_equal((intptr_t)thread_result, 0);
  assert_int_equal(get_size(q), 50);
}

static void test_mutex_unlock_after_pop(void** state) {
  Queue* q = (Queue*)*state;
  pthread_t tid;
  add_multi_elems(q);
  queue_try_lock(q);
  int rc = pthread_create(&tid, NULL, remove_multiple_elems, q);
  assert_int_equal(rc, 0);

  struct timespec ts = {0, 1000000L};
  nanosleep(&ts, NULL);
  queue_unlock(q);
  void* thread_result;
  pthread_join(tid, &thread_result);
  assert_int_equal((intptr_t)thread_result, 0);
  assert_true(is_queue_empty(q));
  assert_int_equal(get_size(q), 0);
}

static void test_when_queue_null_then_empty(void** state) {
  Queue* queue = (Queue*)*state;
  assert_true(is_queue_empty(NULL));
  assert_int_equal(get_size(NULL), 0);
  assert_false(add(NULL, 1));
  int dummy = 0;
  assert_false(remove_from_queue(NULL, &dummy));
}

static void test_destroy_stack_with_elements(void** state) {
  Queue* q = (Queue*)*state;
  assert_true(add(q, 1));
  assert_true(add(q, 2));
  destroy_queue(q);
  *state = NULL;
}

static void test_unlock_queue_null_safe(void** state) {
  (void)state;
  queue_unlock(NULL);
  assert_true(true);
}

static void test_queue_unlock_allows_operations(void** state) {
  Queue* q = (Queue*)*state;
  assert_int_equal(queue_try_lock(NULL), -1);
  queue_unlock(q);
  assert_true(add(q, 5));
  int value = 0;
  assert_true(remove_from_queue(q, &value));
  assert_int_equal(value, 5);
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test_setup_teardown(test_queue_basic_operations, setup,
                                      tear_down),
      cmocka_unit_test_setup_teardown(
          test_element_from_empty_queue_can_not_be_removed, setup, tear_down),
      cmocka_unit_test_setup_teardown(test_add_and_remove_mulitple_elements,
                                      setup, tear_down),
      cmocka_unit_test_setup_teardown(test_mutex_unlock_after_push, setup,
                                      tear_down),
      cmocka_unit_test_setup_teardown(test_mutex_unlock_after_pop, setup,
                                      tear_down),
      cmocka_unit_test_setup_teardown(test_when_queue_null_then_empty, setup,
                                      tear_down),
      cmocka_unit_test_setup_teardown(test_destroy_stack_with_elements, setup,
                                      tear_down),
      cmocka_unit_test_setup_teardown(test_unlock_queue_null_safe, setup,
                                      tear_down),
      cmocka_unit_test_setup_teardown(test_queue_unlock_allows_operations,
                                      setup, tear_down),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
