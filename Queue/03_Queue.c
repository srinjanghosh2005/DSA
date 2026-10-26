// Queue using Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void linked_list_traversal(struct Node *ptr){
    printf("Printing the elements of this linked list--\n");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(int value){
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Queue is full.\n");
    }
    else{
        n->data = value;
        n->next = NULL;
        if(front == NULL){
            // front == NULL also means rear == NULL
            front = rear = n;
        }
        else{
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue(){
    int val = -1;
    struct Node *ptr = front;
    if(front == NULL){
        printf("Queue is empty.\n");
    }
    else{
        front = front->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main(){
    linked_list_traversal(front);

    printf("Dequeuing element: %d\n", dequeue());
    enqueue(16);
    enqueue(23);
    enqueue(35);
    printf("Dequeuing element: %d\n", dequeue());
    enqueue(56);

    linked_list_traversal(front);
    return 0;
}