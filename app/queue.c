#include <stdio.h>

#define MAX_SIZE 5

typedef struct queue {
  int data[MAX_SIZE];
  int *front;
  int *rear;
} queue;

void initQueue(queue *q) {
  q->front = NULL;
  q->rear = NULL;
}

int isEmpty(queue *q) {
  if (q->front == NULL && q->rear == NULL) return 1;
  if (q->front > q->rear) return 1;
  return 0;
}

int isFull(queue *q) {
  if (&(q->data[MAX_SIZE - 1]) == q->rear) {
    return 1;
  }
  return 0;
}

int enqueue(queue *q, int data) {
  if (isEmpty(q)) {
    q->data[0] = data;
    q->front = q->data;
    q->rear = q->data;
    return 1;
  }
  if (isFull(q)) {
    printf("queue is full!!\n");
    return 0;
  }
  *(q->rear + 1) = data;
  q->rear = q->rear + 1;

  return 1;
}

int dequeue(queue *q) {
  if (isEmpty(q)) {
    printf("Queue IS EMPTY!!\n");
    return 0;
  }
  *(q->rear) = 0;
  q->rear = q->rear - 1;
  return 1;
}

int *front(queue *q) {
  if (isEmpty(q)) {
    printf("Queue IS EMPTY!!\n");
    return NULL;
  }
  return q->front;
}

int *rear(queue *q) {
  if (isEmpty(q)) {
    printf("Queue IS EMPTY!!\n");
    return NULL;
  }
  return q->rear;
}

void printQueue(queue *q) {
  if (isEmpty(q)) {
    printf("Queue IS EMPTY!!\n");
  } else {
    int *now = q->front;
    int count = 0;
    while (&(q->data[count]) <= q->rear) {
      printf("%d ", q->data[count]);
      count++;
      if (count > MAX_SIZE) {
        printf("Queue overflow!!\n");
        break;
      }
    }
    printf("\n");
  }
}

int main() {
  queue q;
  initQueue(&q);
  enqueue(&q, 3);
  printQueue(&q);

  enqueue(&q, 4);
  printQueue(&q);

  int *q_rear = rear(&q);
  if (q_rear != NULL) {
    printf("rear: %d \n", *q_rear);
  }

  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);

  printQueue(&q);

  return 0;
}