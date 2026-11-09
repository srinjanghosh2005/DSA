// Search a key in a binary search tree
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

struct Node *search(struct Node *root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if(root->data > key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
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

    struct Node *n = search(ptr, 4);
    if(n != NULL){
        printf("Found: %d ", n->data);
    }
    else{
        printf("Element not found.");
    }

    return 0;
}