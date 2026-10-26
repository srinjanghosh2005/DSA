#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head){
    struct Node *p = head;
    do{
        printf("%d ", (p->data));
        p = p->next;
    }while(p != head);
}

// case 1: Deletion at beginning
struct Node *deleteFirst(struct Node *head){

}

// case 2: Deletion at index
struct Node *deleteAtIndex(struct Node *head, int index){

}

// case 3: Deletion at the end
struct Node *deleteAtEnd(struct Node *head){

}

// case 4: Delete a node with given value(first value)
struct Node *deletevalue(struct Node *head, int value){

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

    printf("Linked list before deletion--\n");
    linkedListTraversal(head);

    // case 1: Deletion at beginning
    // head = deleteFirst(head);


    printf("\nLinked list after deletion--\n");
    linkedListTraversal(head);

    return 0;
} 