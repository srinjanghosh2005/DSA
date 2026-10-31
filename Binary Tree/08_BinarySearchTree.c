// Insertion in Binary Search Tree

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

// Binary Search Tree looks like
//        5
//       / \
//      3   6
//     / \
//    1   4
//   / \
//  N   N (N = NULL)
// root = 3, prev = 5 || root = 1, prev = 3 || root = NULL, prev = 1 (inserting 2)

void insert(struct Node *root, int key){
    struct Node *prev = NULL;
    while(root != NULL){
        prev = root;
        if(key == root->data){
            printf("Cannot insert %d, already in BST.", key);
            return;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct Node *new = createNode(key);
    new->data = key;  
    if(key < prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
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

    insert(ptr, 8);
    printf("%d", ptr->right->right->data);

    return 0;
}