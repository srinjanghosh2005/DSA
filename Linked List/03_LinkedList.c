#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// Linked List Traversal
void linkedlistTraversal(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// case 1: Deletion at beginning
struct Node *deleteFirst(struct Node *head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// case 2: Deletion at index
struct Node *deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    // from index 1
    // for(int i = 0; i < index-1; i++){ p = p->next; q = q->next; }
    int i = 0;
    while(i != index-1){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

// case 3: Deletion at the end
struct Node *deleteAtEnd(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// case 4: Delete a node with given value(first value)
struct Node *deletevalue(struct Node *head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data != value && q->next !=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
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

    third->data = 8;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion--\n");
    linkedlistTraversal(head);

    // Case 1:
    // head = deleteFirst(head);
    // Case 2:
    // head = deleteAtIndex(head, 2);
    // Case 3:
    // head = deleteAtEnd(head);
    // case 4:
    head = deletevalue(head, 8);

    printf("Linked list after deletion--\n");
    linkedlistTraversal(head);
    
    return 0;
}