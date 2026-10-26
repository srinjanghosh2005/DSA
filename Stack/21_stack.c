// Multiple parenthesis checking --> (), {}, []

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *arr;
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

void push(struct stack *ptr, char value){
    if(isFull(ptr)){
        printf("Stack Overflow.\n");
    }
    else{
        ptr->top ++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow.\n");
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top --;
        return val;
    }
}

int match(char a, char b){
    if(a == '(' && b == ')'){
        return 1;
    }
    if(a == '{' && b == '}'){
        return 1;
    }
    if(a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

// Parenthesis Checking
int parenthesisMatch(char *exp){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_char;
    for(int i = 0; exp[i] != '\0'; i ++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(sp, exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_char = pop(sp);
            if(! match(popped_char, exp[i])){
                return 0;
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    free(sp->arr);
    free(sp);
}

int main(){
    char exp[20];
    scanf("%s", exp);

    if(parenthesisMatch(exp)){
        printf("Matching parenthesis.\n");
    }
    else{
        printf("Parenthesis not matching.\n");
    }

    return 0;
}