// Deletion in Binary Search Tree

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
    struct Node *ptr = createNode(5);
    struct Node *ptr1 = createNode(3);
    struct Node *ptr2 = createNode(6);
    struct Node *ptr3 = createNode(1);
    struct Node *ptr4 = createNode(4);

    // Linking the nodes
    ptr->left = ptr1;
    ptr->right = ptr2;
    ptr1->left = ptr3;
    ptr1->right = ptr4;

    insert(ptr, 6);
    printf("%d", ptr->right->right->data);

    return 0;
}