// Linked representation of Binary Tree(Kind of similar to doubly linked list)
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(){
    /*
    // Constructing the root nodes
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = 2;
    ptr->left = ptr->right = NULL;
    // constructing the second node
    struct Node *ptr1;
    ptr1 = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = 1;
    ptr1->left = ptr1->right = NULL;
    // Constructing the third node
    struct Node *ptr2;
    ptr2 = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = 4;
    ptr2->left = ptr2->right = NULL;
    */

    // Constructing nodes --> using functions(Recomended)
    struct Node *ptr = createNode(2);
    struct Node *ptr1 = createNode(1);
    struct Node *ptr2 = createNode(4);

    //linking the node
    ptr->left = ptr1;
    ptr->right = ptr2;

    return 0;
}