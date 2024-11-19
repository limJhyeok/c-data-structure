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

int deleteAtHead(void) {
  if (g_head_pointer == NULL) {
    printf("empty node\n");
    return 0;
  }
  Node *temp = g_head_pointer;
  g_head_pointer = g_head_pointer->next;

  printf("delete %s data \n", temp->data);
  free(temp);

  return 1;
}

int deleteAtTail(void) {
  if (g_head_pointer == NULL) {
    printf("EMPTY NODE \n");
    return 0;
  }
  Node *now = g_head_pointer;
  Node *prev = NULL;
  while (now->next != NULL) {
    prev = now;
    now = now->next;
  }
  prev->next = NULL;
  printf("delete at tail function executed");
  printf("delete %s data \n", now->data);
  free(now);
  return 1;
}

int deleteAtPosition(int i) {
  if (i == 0) {
    printf("delete at position {%d} function executed\n", i);
    deleteAtHead();
    return 1;
  }

  Node *now = g_head_pointer;
  Node *prev = NULL;
  int count = 0;
  while (count != i && now != NULL) {
    count++;
    prev = now;
    now = now->next;
  }
  if (now == NULL) {
    printf("ERROR: delete at position {%d} function can't be excuted.\n", i);
    return 0;
  }
  prev->next = now->next;
  printf("delete at position {%d} function executed\n", i);
  printf("delete %s data \n", now->data);

  free(now);
  return 1;
}

int freeList(void) {
  if (g_head_pointer == NULL) {
    printf("Empty List");
    return 1;
  }
  Node *now = g_head_pointer;
  Node *prev = NULL;
  while (now) {
    prev = now;
    now = now->next;
    free(prev);
  }
  g_head_pointer = NULL;
  return 1;
}

int updateAtHead(char *data) {
  if (g_head_pointer == NULL) {
    printf("There is no data to update.");
    return 0;
  }
  strcpy(g_head_pointer->data, data);
  return 0;
}

int updateAtTail(char *data) {
  if (g_head_pointer == NULL) {
    printf("There is no data to update.");
    return 0;
  }
  Node *now = g_head_pointer;
  Node *prev = NULL;
  while (now) {
    prev = now;
    now = now->next;
  }
  strcpy(prev->data, data);
  return 1;
}

int updateAtPosition(int i, char *data) {
  if (g_head_pointer == NULL) {
    printf("There is no data to update.\n");
    return 0;
  }
  if (i == 0) {
    updateAtHead(data);
    return 1;
  }
  Node *now = g_head_pointer;
  int count = 0;
  while (count != i) {
    count++;
    now = now->next;
    if (now == NULL) {
      printf("update at {%d} can't be accomplished\n", i);
      return 0;
    }
  }
  if (now == NULL) {
    printf("update at {%d} can't be accomplished\n", i);
    return 0;
  }
  strcpy(now->data, data);
  return 1;
}

Node *search(char *data) {
  if (g_head_pointer == NULL) {
    printf("There is no data to search.\n");
    return NULL;
  }
  Node *now = g_head_pointer;
  while (now) {
    if (strcmp(now->data, data) == 0) {
      return now;
    }
    now = now->next;
  }
  printf("'%s' isn't in the list.", data);
  return NULL;
}

void printNodeData(void) {
  struct Node *now = g_head_pointer;
  if (now == NULL) {
    printf("Empty List\n");
  }
  while (now != NULL) {
    printf("now address: %p, data: %s, next pointer: %p \n", now, now->data,
           now->next);
    now = now->next;
  }
  printf("====================\n");
}

int main() {
  insertAtTail("tail");
  printNodeData();

  updateAtHead("Head Update");
  printNodeData();

  updateAtTail("Tail updated");
  printNodeData();

  updateAtPosition(0, "index 0 updated");
  printNodeData();

  insertAtHead("first");
  updateAtPosition(2, "index 2 updated");

  printNodeData();
  insertAtHead("second");
  printNodeData();
  updateAtPosition(2, "index 2 update");
  printNodeData();

  Node *searched = search("index 1 update");
  printf("'%s' is founded\n", searched->data);

  freeList();

  printNodeData();
  return 0;
}
