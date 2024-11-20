#include <stdio.h>

#define MAX_SIZE 5

typedef struct stack {
  int data[MAX_SIZE];
  int *top;
} stack;

void initStack(stack *stk) { stk->top = NULL; }

int isEmpty(stack *stk) {
  if (stk->top == NULL) return 1;
  return 0;
}

void printStack(stack *stk) {
  if (isEmpty(stk)) {
    printf("STACK IS EMPTY!!\n");
  } else {
    int count = 0;
    while (&(stk->data[count]) <= stk->top) {
      printf("%d ", stk->data[count]);
      count++;
      if (count > MAX_SIZE) {
        printf("OVER FLOW ERROR!!!!");
        break;
      }
    }
    printf("\n");
  }
}

int isFull(stack *stk) {
  if (&(stk->data[MAX_SIZE - 1]) <= stk->top) {
    return 1;
  }
  return 0;
}

int push(stack *stk, int data) {
  if (isEmpty(stk)) {
    stk->data[0] = data;
    stk->top = stk->data;
    return 0;
  }
  if (isFull(stk)) {
    printf("STACK IS FULL!!! \n");
    return 0;
  }
  *(stk->top + 1) = data;
  stk->top = stk->top + 1;
  return 1;
}

int pop(stack *stk) {
  if (isEmpty(stk)) {
    printf("STACK IS EMPTY!!\n");
    return 0;
  }
  *stk->top = 0;
  stk->top = stk->top - 1;
  return 1;
}

int *top(stack *stk) { return stk->top; }

int main() {
  stack stk;
  initStack(&stk);
  push(&stk, 2);
  push(&stk, 3);
  push(&stk, 3);
  push(&stk, 3);
  push(&stk, 3);

  printf("max_size -1 address: %p \n", &(stk.data[MAX_SIZE - 1]));
  printf("top address: %p \n", stk.top);
  printStack(&stk);
  printf("is Full?: %d \n", isFull(&stk));
  push(&stk, 5);
  printStack(&stk);
  return 0;
}