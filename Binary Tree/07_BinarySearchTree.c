// Itertive Search in Binary Search Tree
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

struct Node *iterSearch(struct Node *root, int key){
    while(root != NULL){
        if(key == root->data){
            return root;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

int main(){
    struct Node *ptr = createNode(5);
    struct Node *ptr1 = createNode(3);
    struct Node *ptr2 = createNode(6);
    struct Node *ptr3 = createNode(1);
    struct Node *ptr4 = createNode(4);
    // Binary Search Tree looks like
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the nodes
    ptr->left = ptr1;
    ptr->right = ptr2;
    ptr1->left = ptr3;
    ptr1->right = ptr4;

    struct Node *n = iterSearch(ptr, 6);
    if(n != NULL){
        printf("Found: %d ", n->data);
    }
    else{
        printf("Element not found.");
    }

    return 0;
}