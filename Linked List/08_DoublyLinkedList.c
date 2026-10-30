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
void reverseTraversal(struct Node *tail){
    while(tail != NULL){
        printf("%d ", tail->data);
        tail = tail->prev;
    }
    printf("\n");
}

// case 1: Insert at the beginning
struct Node *deleteFirst(struct Node *head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    struct Node *new = (struct Node *) malloc(sizeof(struct Node));
    new = head->next;
    head->next = new;
    head->prev = NULL;
    new->prev = head;
    return head;
}

// case 2: Deletion at the end
struct Node *deleteEnd(struct Node *tail){
    struct Node *ptr  = tail;
    tail = tail->prev;
    free(ptr);
    struct Node *new_tail = tail;
    new_tail->next = NULL;
    return tail;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *tail;
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    tail = (struct Node *) malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 48;
    head->next = second;

    second->prev = head;
    second->data = 16;
    second->next = third;

    third->prev = second;
    third->data = 54;
    third->next = tail;

    tail->prev = third;
    tail->data = 23;
    tail->next = NULL;

    printf("Before Deletion ----\n");
    doubly_linked_list_traversal(head);

    printf("Before Deletion(Reverse) --\n");
    reverseTraversal(tail);

    // Case 1
    head = deleteFirst(head);

    // Case 2
    tail = deleteEnd(tail);

    printf("After Deletion ----\n");
    doubly_linked_list_traversal(head);

    printf("After Deletion(Reverse) --\n");
    reverseTraversal(tail);

    return 0;
}