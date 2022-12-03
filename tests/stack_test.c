#include "../stack.h"
#include "../hashtable.h"
#include "common.h"

static void test_empty() {
  LinkedStack* stack;
  stack_create(&stack);

  void* temp;
  assert_true("Stack should be empty", !stack_pop(&stack, &temp));
}

static void test_push_pop() {
  LinkedStack* stack;
  stack_create(&stack);

  int n = TOTAL_COUNT;
  int i;
  for (i = 0; i < n; i++) {
    void* temp;
    stack_push(&stack, INT2VOIDP(n - i - 1));
  }

  for (i = 0; i < n; i++) {
    void* temp;
    assert_true("Stack should be empty", stack_pop(&stack, &temp));
    assert_true("Should contain the right valud", VOIDP2INT(temp) == i);
  }
}

static void test_clear() {
  LinkedStack* stack;
  stack_create(&stack);

  int n = 1000;
  int i;
  for (i = 0; i < n; i++) {
    void* temp;
    stack_push(&stack, INT2VOIDP(n - i - 1));
  }

  stack_destroy(&stack);
  void* temp;
  assert_true("Stack should be empty", !stack_pop(&stack, &temp));
}

void test_stack() {
  TEST tests[] = {{test_empty, "empty stack consistency"},
                  {test_push_pop, "push pop consistency"},
                  {test_clear, "clear consistency"}};

  run_tests("stack", tests, 3);
}
