#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL; // make top global pointer so we don't need to pass the address to the function

void linkedlistTravesal(struct Node *top){
    while(top != NULL){
        printf("%d ", top->data);
        top = top->next;
    }
}

int isEmpty(struct Node *top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
} 

int isFull(struct Node *top){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node *push(struct Node *top, int value){
    if (isFull(top)){
        printf("Stack Overflow.\n");
    }
    else{
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = value;
        n->next = top;
        top = n;
        return top;
    }
}

// Pop operation *top --> error bcs it used as both global and local variable
int pop(struct Node *tp){
    if(isEmpty(tp)){
        printf("stack Underflow.\n");
    }
    else{
        struct Node *n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main(){
    top = push(top, 7);
    top = push(top, 12);
    top = push(top, 18);
    top = push(top, 28);

    int element = pop(top); // &top --> bcs if we don't pass address the top will not change in main function(pass by referenece concept)
    printf("Popped element is %d.\n", element);

    linkedlistTravesal(top);

    return 0;
}