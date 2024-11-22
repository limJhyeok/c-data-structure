#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
  char data[20];
  struct Node *prev;
  struct Node *next;
} Node;

Node *g_head_pointer;
Node *g_tail_pointer;
int g_list_size = 0;

void initList() {
  g_head_pointer = (Node *)malloc(sizeof(Node));
  g_tail_pointer = (Node *)malloc(sizeof(Node));
  g_head_pointer->next = g_tail_pointer;
  g_tail_pointer->prev = g_head_pointer;
}

int isEmpty() {
  if (g_head_pointer->next == g_tail_pointer) {
    return 1;
  }
  return 0;
}

int releaseList() {
  if (isEmpty()) {
    return 1;
  } else {
    Node *now = g_head_pointer->next;
    while (now != g_tail_pointer) {
      Node *prev = now;
      now = now->next;
      free(prev);
    }
    initList();
    g_list_size = 0;
  }
}

void printList() {
  if (isEmpty()) {
    printf("EMPTY LIST!!\n");
  } else {
    Node *now = g_head_pointer;
    while (now->next != g_tail_pointer) {
      now = now->next;
      printf("%s ", now->data);
    }
    printf("\n");
  }
}

Node *findNode(char *data) {
  Node *now = g_head_pointer->next;
  while (now != g_tail_pointer) {
    if (strcmp(now->data, data) == 0) {
      return now;
    }
    now = now->next;
  }
  return NULL;
}

int deleteNode(Node *node) {
  if (node == g_head_pointer || node == g_tail_pointer) {
    printf("head or tail node couldn't be deleted.\n");
    return 0;
  }

  Node *prev_node = node->prev;
  Node *next_node = node->next;
  prev_node->next = next_node;
  next_node->prev = prev_node;
  free(node);
  g_list_size--;
  return 1;
}

int insertAtHead(char *data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  strcpy(new_node->data, data);
  Node *original_first_node = g_head_pointer->next;
  g_head_pointer->next = new_node;
  new_node->prev = g_head_pointer;
  new_node->next = original_first_node;
  original_first_node->prev = new_node;
  g_list_size++;
  return 1;
}

int insertAtTail(char *data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  strcpy(new_node->data, data);
  Node *original_last_node = g_tail_pointer->prev;
  g_tail_pointer->prev = new_node;
  new_node->prev = original_last_node;
  new_node->next = g_tail_pointer;
  original_last_node->next = new_node;
  g_list_size++;
  return 1;
}

int getSize() { return g_list_size; }

int main() {
  initList();
  insertAtHead("insert At Head");
  insertAtTail("insert At Tail");
  Node *find = findNode("insert At Tail");
  if (find != NULL) {
    printf("find node: %s \n", find->data);
  }
  printList();
  printf("size: %d\n", getSize());

  deleteNode(find);
  printList();
  printf("size: %d\n", getSize());
  return 0;
}