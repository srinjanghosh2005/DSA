#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top == (ptr->size-1)){
        return 1;
    }
    else{
        return 0;
    }
}

// Pushing a value into the stack
void push(struct stack *ptr, int value){
    if(isFull(ptr)){
        printf("Stack Overflow!Cannot push %d to the stack\n", value);
    }
    else{
        ptr->top ++;
        ptr->arr[ptr->top] = value;
    }
}

// Poping an element from stack
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow!Cannot pop from the stack.\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top --;
        return val;
    }
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack has been created successfully.\n");

    printf("Before Pushing\nFull: %d,Empty: %d\n", isFull(s), isEmpty(s));

    push(s, 5);
    push(s, 6);
    push(s, 21);
    push(s, 3);
    push(s, 16);
    push(s, 2);
    push(s, 9);
    push(s, 11); // -->Pushed  values
    push(s, 8); // Stack Overflow since the size of the stack is 8

    printf("After Pushing\nFull: %d,Empty: %d\n", isFull(s), isEmpty(s));

    printf("Popped %d from the stack.\n", pop(s)); // Last in first out
    printf("Popped %d from the stack.\n", pop(s));
    printf("Popped %d from the stack.\n", pop(s));
    printf("Popped %d from the stack.\n", pop(s));

    printf("After Poping\nFull: %d,Empty: %d\n", isFull(s), isEmpty(s));

    return 0;
}