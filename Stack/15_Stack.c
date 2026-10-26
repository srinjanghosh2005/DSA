// 5(0), 6(1), 21(2), 3(3), 16(4) --> Index-wise seperation of stack

// 5(5), 6(4), 21(3), 3(2), 16(1) --> Position-wise seperation of stack(Used in case of peek operation) 

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

void push(struct stack *ptr, int value){
    if(isFull(ptr)){
        printf("Stack Overflow!Cannot push %d to the stack\n", value);
    }
    else{
        ptr->top ++;
        ptr->arr[ptr->top] = value;
    }
}

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

// Peek Operation
int peek(struct stack *ptr, int pos){
    int arrayInd = ptr->top - pos + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack,\n");
        return -1;
    }
    else{
        return ptr->arr[arrayInd];
    }
}

int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 5);
    push(s, 6);
    push(s, 21);
    push(s, 3);
    push(s, 16);

    // Peeking values in stack
    for(int i = 1; i <= s->top+1; i++){
        printf("Element at %d position is %d\n", i, peek(s, i));
    }

    return 0;
}