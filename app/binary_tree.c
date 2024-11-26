#include <malloc.h>
#include <stdio.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

Node* g_p_root = NULL;

int insertNode(int data) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  if (g_p_root == NULL) {
    g_p_root = new_node;
    return 1;
  }

  Node* now = g_p_root;
  while (now) {
    if (now->data < data) {
      if (now->right == NULL) {
        now->right = new_node;
        return 1;
      }
      now = now->right;
    } else {
      if (now->left == NULL) {
        now->left = new_node;
        return 1;
      }
      now = now->left;
    }
  }

  return 0;
}

void preorderTraverse(Node* node) {
  if (node == NULL) {
    printf("===EMPTY TREE===\n");
  } else {
    printf("%d ", node->data);
    if (node->left != NULL) {
      preorderTraverse(node->left);
    }
    if (node->right != NULL) {
      preorderTraverse(node->right);
    }
  }
  if (node == g_p_root) {
    printf("\n");
  }
}

void inorderTraverse(Node* node) {
  if (node == NULL) {
    printf("===EMPTY TREE===\n");
  } else {
    if (node->left != NULL) {
      inorderTraverse(node->left);
    }
    printf("%d ", node->data);
    if (node->right != NULL) {
      inorderTraverse(node->right);
    }
  }
  if (node == g_p_root) {
    printf("\n");
  }
}

void postorderTraverse(Node* node) {
  if (node == NULL) {
    printf("===EMPTY TREE===\n");
  } else {
    if (node->left != NULL) {
      postorderTraverse(node->left);
    }
    if (node->right != NULL) {
      postorderTraverse(node->right);
    }
    printf("%d ", node->data);
  }
  if (node == g_p_root) {
    printf("\n");
  }
}

Node* findNode(int data) {
  if (g_p_root == NULL) {
    printf("===EMPTY TREE===\n");
    return NULL;
  }
  Node* now = g_p_root;
  while (now) {
    if (now->data == data) {
      return now;
    }
    if (now->data < data) {
      if (now->right == NULL) {
        printf("%d is not in tree\n", data);
        return NULL;
      }
      now = now->right;
      continue;
    }
    if (now->data > data) {
      if (now->left == NULL) {
        printf("%d is not in tree\n", data);
        return NULL;
      }
      now = now->left;
    }
  }
  printf("%d is not in tree\n", data);
  return NULL;
}

int deleteNode(int data) {
  // Node* find_node = findNode(data);
  // if (find_node == NULL){
  //     return 0;
  // }
  // printf("delete: %p", find_node);

  // tree 재정렬

  // free(find_node);
  // return 1;
}

void freeTree(Node* root);

int main() {
  insertNode(10);
  insertNode(5);
  insertNode(2);
  insertNode(7);
  insertNode(6);
  insertNode(8);
  insertNode(12);
  insertNode(14);
  insertNode(13);

  // deleteNode(5);

  inorderTraverse(g_p_root);
  return 0;
}