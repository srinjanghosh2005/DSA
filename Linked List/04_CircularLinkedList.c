#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// Traversal in circular linked list
void linkedListTraversal(struct Node *head){
    struct Node *p = head;
    // can also use while loop
    do{
        printf("%d ", (p->data));
        p = p->next;
    }while(p != head);
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    // Link first and second node
    head->data = 7;
    head->next = second;
    // Link second and third node
    second->data = 11;
    second->next = third;
    // Terminate the list at head node
    third->data = 4;
    third->next = head;

    linkedListTraversal(head);

    return 0;
}