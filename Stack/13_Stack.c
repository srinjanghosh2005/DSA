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
    if(ptr->top == (ptr->size - 1)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));

    struct stack *s; // calling functions become easier
    s->size = 8;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    
    // Pushing element manually
    s->arr[0] = 7;
    s->top++;

    // Check if stack is empty
    if(isEmpty(s)){
        printf("Stack is empty.\n");
    }
    else{
        printf("Stack is not empty.\n");
    }

    return 0;
}