#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

// Traversal in Doubly Linked List
void doubly_linked_list_traversal(struct Node *ptr){
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Reverse Traversal
void reverseTraversal(struct Node *head){
    struct Node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    // Now ptr is at ending pos
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

struct Node *deleteFirst(struct Node *head){

}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 48;
    head->next = second;

    second->prev = head;
    second->data = 16;
    second->next = third;

    third->prev = second;
    third->data = 54;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 23;
    fourth->next = NULL;

    // traversal
    printf("Before Insertion ----\n");
    doubly_linked_list_traversal(head);

    // reverse Traversal
    printf("Before Insertion(Reverse) --\n");
    reverseTraversal(head);


    printf("After Insertion ----\n");
    doubly_linked_list_traversal(head);

    printf("After Insertion(Reverse) --\n");
    reverseTraversal(head);


    return 0;
}