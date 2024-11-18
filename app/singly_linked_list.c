#include <malloc.h>
#include <stdio.h>
#include <string.h>
typedef struct Node {
  char data[20];
  struct Node *next;
} Node;

Node *g_head_pointer = NULL;

int insertAtHead(char *data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  memset(new_node, 0, sizeof(new_node));
  strcpy(new_node->data, data);
  new_node->next = NULL;
  if (g_head_pointer == NULL) {
    g_head_pointer = new_node;
    return 1;
  }
  new_node->next = g_head_pointer;
  g_head_pointer = new_node;
  return 1;
}

int insertAtTail(char *data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  memset(new_node, 0, sizeof(new_node));
  strcpy(new_node->data, data);
  new_node->next = NULL;
  if (g_head_pointer == NULL) {
    g_head_pointer = new_node;
    return 1;
  }
  // traverse
  Node *now = g_head_pointer;
  while (now->next != NULL) {
    now = now->next;
  }
  now->next = new_node;

  return 1;
}

int insertAtPosition(char *data, int i) {
  if (i == 0) insertAtHead(data);
  Node *new_node = (Node *)malloc(sizeof(Node));
  memset(new_node, 0, sizeof(new_node));
  strcpy(new_node->data, data);
  new_node->next = NULL;

  int count = 1;
  Node *now = g_head_pointer;
  while (count != i) {
    // refactoring L. 62~65
    if (now == NULL) {
      printf("insert at {%d} can't be accomplished\n", i);
      return 0;
    }
    now = now->next;
    count++;
  }
  if (now == NULL) {
    printf("insert at {%d} can't be accomplished \n", i);
    return 0;
  }
  new_node->next = now->next;
  now->next = new_node;
  return 1;
}

void PrintNodeData(void) {
  struct Node *now = g_head_pointer;
  while (now != NULL) {
    printf("now address: %p, data: %s, next pointer: %p \n", now, now->data,
           now->next);
    now = now->next;
  }
  printf("====================\n");
}

int main() {
  insertAtTail("tail");
  PrintNodeData();
  insertAtHead("first");
  PrintNodeData();
  insertAtHead("second");
  PrintNodeData();

  insertAtPosition("inserted at 1", 4);
  PrintNodeData();

  insertAtPosition("newly inserted at 1", 1);
  PrintNodeData();
  return 0;
}
