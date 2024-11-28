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

Node* findParent(Node* node) {
  if (g_p_root == NULL) {
    printf("===EMPTY TREE===\n");
    return NULL;
  }
  Node* now = g_p_root;
  Node* prev = NULL;
  while (now) {
    if (now->data == node->data) {
      return prev;
    }
    if (now->data < node->data) {
      if (now->right == NULL) {
        return NULL;
      }
      prev = now;
      now = now->right;
      continue;
    }
    if (now->data > node->data) {
      if (now->left == NULL) {
        return NULL;
      }
      prev = now;
      now = now->left;
    }
  }
  return NULL;
}

Node* findMinNode(Node* node) {
  Node* now = node;
  while (now) {
    if (now->left == NULL) {
      return now;
    }
    now = now->left;
  }
  return NULL;
}

int isLeaf(Node* node) {
  if (node->left == NULL && node->right == NULL) {
    return 1;
  }
  return 0;
}

int deleteNode(int data) {
  Node* find_node = findNode(data);
  if (find_node == NULL) {
    return 0;
  }

  // case 0: leaf 노드일 때(child X)
  if (find_node->left == NULL && find_node->right == NULL) {
    Node* parent = findParent(find_node);
    if (parent == NULL) {
      g_p_root = NULL;
      free(find_node);
      return 1;
    }
    if (parent->left == find_node) {
      parent->left = NULL;
      free(find_node);
      return 1;
    }
    if (parent->right == find_node) {
      parent->right = NULL;
      free(find_node);
      return 1;
    }
    return 1;
  }
  // case 1: 오른쪽 child만 존재
  if (find_node->left != NULL && find_node->right == NULL) {
    Node* replace = find_node->left;
    Node* parent = findParent(find_node);
    if (parent == NULL) {
      g_p_root = replace;
      free(find_node);
      return 1;
    }
    if (parent->left == find_node) {
      parent->left = replace;
      free(find_node);
      return 1;
    }
    if (parent->right == find_node) {
      parent->right = replace;
      free(find_node);
      return 1;
    }
  }
  // case 2: 왼쪽 child만 존재
  if (find_node->left == NULL && find_node->right != NULL) {
    Node* replace = find_node->right;
    Node* parent = findParent(find_node);
    if (parent == NULL) {
      g_p_root = replace;
      free(find_node);
      return 1;
    }
    if (parent->left == find_node) {
      parent->left = replace;
      free(find_node);
      return 1;
    }
    if (parent->right == find_node) {
      parent->right = replace;
      free(find_node);
      return 1;
    }
  }

  // case 3: child 모두 존재
  if (find_node->left != NULL && find_node->right != NULL) {
    Node* replace = findMinNode(find_node->right);
    Node* parent = findParent(find_node);
    Node* replace_parent = findParent(replace);
    if (parent == NULL) {
      if (find_node->right == replace) {
        Node* root_left = find_node->left;
        replace->left = root_left;
        g_p_root = replace;
        free(find_node);
        return 1;
      }
      find_node->data = replace->data;
      if (replace_parent->left == replace) {
        replace_parent->left = NULL;
      }
      if (replace_parent->right == replace) {
        replace_parent->right = NULL;
      }
      free(replace);
      return 1;
    }

    find_node->data = replace->data;

    if (replace_parent->right == replace) {
      replace_parent->right = NULL;
    }
    if (replace_parent->left == replace) {
      replace_parent->left = NULL;
    }
    free(replace);
    return 1;
    // if (parent->left == find_node){
    //   parent->left = replace;
    //   replace->right = find_node->right;
    //   replace->left = find_node->left;
    //   replace_parent->left = NULL;
    //   free(replace);
    //   return 1;
    // }

    // if(parent->right == find_node){
    //   parent->right = replace;
    //   replace->right = find_node->right;
    //   replace->left = find_node->left;
    //   replace_parent->left = NULL;
    //   free(find_node);
    //   return 1;
    // }
  }
  return 0;
}

void freeTree(Node* root);

int main() {
  insertNode(10);
  insertNode(4);
  insertNode(2);
  insertNode(7);
  insertNode(6);
  insertNode(8);
  insertNode(13);
  insertNode(15);
  insertNode(17);
  insertNode(16);
  deleteNode(10);
  inorderTraverse(g_p_root);
  deleteNode(4);
  deleteNode(2);
  deleteNode(15);

  inorderTraverse(g_p_root);
  return 0;
}