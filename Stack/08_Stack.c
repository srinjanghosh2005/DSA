// Parenthesis Checking(only single type off bracket)

#include<stdio.h>
#include<stdlib.h>

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

// Parenthesis Checking
int parenthesisMatch(char *exp){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for(int i = 0; exp[i] != '\0'; i ++){
        if(exp[i] == '('){
            push(sp, exp[i]);
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            else{
                pop(sp);
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
    // char *exp = "(7*5)-(7*4";  
    // Hardcoded value --> in function parethesisMatch(exp)
    char exp[20];
    scanf("%s", exp);
    if(parenthesisMatch(exp)){
        printf("matching parenthesis.\n");
    }
    else{
        printf("Parenthesis not matching.\n");
    }

    return 0;
}