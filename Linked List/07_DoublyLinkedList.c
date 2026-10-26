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

// case 1: Insert at the beginning
struct Node *insertFirst(struct Node *head, int value){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = head;
    ptr->prev = NULL;
    head->prev = ptr;
    head = ptr;
    return head;
}

// case 2: Insert at the end
struct Node *insertEnd(struct Node *head, int value){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    ptr->data = value;
    ptr->prev = p;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

// case 3: Insert in between
struct Node *insertAtIndex(struct Node *head, int value, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    struct Node *q;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    q = p->next;
    ptr->data = value;
    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
    q->prev = ptr;
    return head;
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

    // Insert element at first
    head = insertFirst(head, 73);

    // Insert element a the end
    head = insertEnd(head, 61);

    // Insert element at index
    head = insertAtIndex(head, 67, 2);

    printf("After Insertion ----\n");
    doubly_linked_list_traversal(head);

    printf("After Insertion(Reverse) --\n");
    reverseTraversal(head);


    return 0;
}