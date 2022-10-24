#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../models/models.h"

Node *createNode(Character c) {
  Node *temp = (Node*)malloc(sizeof(Node));
  strcpy(temp->c.name, c.name);
  strcpy(temp->c.job, c.job);
  temp->c.level = c.level;
  temp->c.damage = c.damage;
  temp->left = temp->right = NULL;
  return temp;
}

void printAll(Node *root) {
  if(root) {
    printf("> %s | %s | lvl. %d | damage: %d\n", root->c.name, root->c.job, root->c.level, root->c.damage);
    printAll(root->left);
    printAll(root->right);
  }
}

Node *insertNode(Node *root, Character c) {
  if(!root) {
    return createNode(c);
  } else if(c.damage < root->c.damage) {
    root->left = insertNode(root->left, c);
  } else if(c.damage > root->c.damage) {
    root->right = insertNode(root->right, c);
  }

  return root;
}

void preOrder(Node *root) {
  if(root) {
    printf(" %d", root->c.damage);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void inOrder(Node *root) {
  if(root) {
    inOrder(root->left);
    printf(" %d", root->c.damage);
    inOrder(root->right);
  }
}

void postOrder(Node *root) {
  if(root) {
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d", root->c.damage);
  }
}

void printData(Node *root) {
  printf("Preorder: ");
  preOrder(root); puts("");
  printf("Inorder: ");
  inOrder(root); puts("");
  printf("Postorder: ");
  postOrder(root); puts("");
}

void popAll(Node *root) {
  if(root) {
    popAll(root->left);
    free(root);
    root = NULL;
    popAll(root->right);
  }
}


// --- ARRAY ---
/*
int arr[] = {1, 3, 5, 7, 9};

for(int i = 0; i < 5; i++) {
 logic here
}
*/

// --- LINKED LIST ---
// 1 -> 3 -> 5 -> 7 -> 9
/*
  curr = head;
  while(curr) {
    // logic here
    curr = curr->next
  }
*/

// --- BINARY SEARCH TREE ---
/*
if(root) {
  traverse(root->left);
  // logic here
  traverse(root->right);
}
*/