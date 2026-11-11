// Addition of polynomial expression

#include<stdio.h>
#include<stdlib.h>

// Structure to represent a single term of polnomial: coefficient * x ^ exponent
struct Node{
    int coeff;
    int expo;
    struct Node *next;
};

// Push a term onto the stack
void push(struct Node *top, int coeff, int expo){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = top;
    top = newNode;
}

// Function to print a polynomial
void printPolynomial(struct Node *top){
    if(top == NULL){
        printf("0\n");
        return;
    }
    struct Node *temp = top;
    while(temp != NULL){
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->next;
        if(temp != NULL){
            if(temp->coeff >= 0){
                printf(" + ");
            }
            else{
                printf(" ");
            }
        }
    }
    printf("\n");
}

// Reverse Stack helper
void reverseStack(struct Node *top){
    struct Node *prev = NULL;
    struct Node *current = top;
    struct Node *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    top = prev;
}

// Function to add two polnomials using stacks
struct Node *addPolynomials(struct Node *p1, struct Node *p2){
    struct Node *result = NULL;

    while(p1 != NULL && p2 != NULL){
        if(p1->expo == p2->expo){
            int sum = p1->coeff + p2->coeff;
            if(sum != 0){
                push(result, sum, p1->expo);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->expo > p2->expo){
            push(result, p1->coeff, p1->expo);
            p1 = p1->next;
        }
        else{
            push(result, p2->coeff, p2->expo);
            p2 = p2->next;
        }
    }

    // Add remaining terms from p1
    while (p1 != NULL) {
        push(result, p1->coeff, p1->expo);
        p1 = p1->next;
    }

    // Add remaining terms from p2
    while (p2 != NULL) {
        push(result, p2->coeff, p2->expo);
        p2 = p2->next;
    }
    return result;
}

int main(){
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;

    // poly1 = 5x^3 + 4x^2 + 2
    push(poly1, 5, 3);
    push(poly1, 4, 2);
    push(poly1, 2, 0);

    // poly2 = 5x^2 - 5x + 3
    push(poly1, 5, 2);
    push(poly1, -5, 1);
    push(poly1, 3, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    // Add polnomials(expects stacks sorted with highest exponent at the bottom/first)
    struct Node *result = addPolynomials(poly1, poly2);
    printf("Sum: ");
    printPolynomial(result);

    return 0;
}