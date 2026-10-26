#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlistTravesal(struct Node *top){
    while(top != NULL){
        printf("%d ", top->data);
        top = top->next;
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

// Peek Operation
int peek(struct Node *top, int pos){
    for(int i = 0; (i < pos-1 && top != NULL); i++){
        top = top->next;
    }
    if(top != NULL){
        return top->data;
    }
    else{
        return -1;
    }
}

// Stack Top Operation
int stackTop(struct Node *top){
    return top->data;
}

// Stack Bottom Operation
int stackBottom(struct Node *top){
    while(top->next != NULL){
        top = top->next;
    }
    return top->data;
}

int main(){
    struct Node *top = NULL;
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);
    
    linkedlistTravesal(top);

    for(int i = 1; i <= 4; i++){
        printf("\nElement at position %d is: %d", i, peek(top, i));
    }

    printf("\nTopmost element in the stack is: %d\n", stackTop(top));

    printf("Bottommost element in the stack is: %d", stackBottom(top));

    return 0;
}