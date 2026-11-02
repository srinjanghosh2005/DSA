// Deletion in Binary Search Tree
// Throwing error
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

// inorder predecessor --> left sub-tree ka right-most child
struct Node *inorder_predecessor(struct Node *root){
    root = root->left;
    while(root != NULL){
        root = root->right;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int value){
    struct Node *inPre;
    // Base Conditions
    if(root == NULL){
        return NULL;
    }
    if(root->right == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    
    // searching for the node to be deleted
    if(value < root->data){
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data){
        root->right = deleteNode(root->right, value);
    }
    // Deletion stratergy when the node is found
    else{
        inPre = inorder_predecessor(root);
        root->data = inPre->data;
        root->left = deleteNode(root->left, inPre->data);
    }
    return root;
}

void inOrder(struct Node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
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

    // Tree looks like
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    inOrder(ptr);
    deleteNode(ptr, 3);
    inOrder(ptr);

    return 0;
}