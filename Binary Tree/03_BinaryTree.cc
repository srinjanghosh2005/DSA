// PostOrder Traversal

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

void postorder(struct Node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    struct Node *ptr = createNode(4);
    struct Node *ptr1 = createNode(1);
    struct Node *ptr2 = createNode(6);
    struct Node *ptr3 = createNode(5);
    struct Node *ptr4 = createNode(2);
    // Tree looks like
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2

    // Linking the nodes
    ptr->left = ptr1;
    ptr->right = ptr2;
    ptr1->left = ptr3;
    ptr1->right = ptr4;

    postorder(ptr);

    return 0;
}