#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("%d ", (ptr->data));
        ptr = ptr->next;
    }while(ptr != head);
    printf("\n");
}

// Case 1: Insertion at head
struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *ptr;
    ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while(p->next != head){
        p = p->next;
    }
    // at this point p points to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

// Case 2: Insertion at end
struct Node *insertionAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

// Case 3: Insertion at index
struct Node *insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
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

    head->data = 4;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 6;
    third->next = fourth;
    fourth->data = 1;
    fourth->next = head;

    printf("Circular Linked list before insertion--\n");
    linkedlistTraversal(head);

    // Case 1: Insertion at head
    // head = insertAtFirst(head, 54);
    // Case 2: Insertion at end
    // head = insertionAtEnd(head, 78);
    // Case 3: Insertion at index
    head = insertAtIndex(head, 23, 2);

    printf("Circular Linked list after insertion--\n");
    linkedlistTraversal(head);
    
    return 0;
}