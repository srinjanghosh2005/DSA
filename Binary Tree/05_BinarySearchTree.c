// Check for Binary Search Tree**
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

// Basically write 'inorder traversal' with modified form 
int isBST(struct Node *root){
    static struct Node *prev = NULL; 
    // "static" retain the value of the variable in 
    //a function despite of having function calls in that functions. 
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
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

    if(isBST(ptr)){
        printf("It is a binary search tree.\n");
    }
    else{
        printf("It is not a binary search tree.\n");
    }

    return 0;
}