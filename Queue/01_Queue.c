// Queue using array
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct queue *q){
    if(q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct queue *q){
    if(q->rear == q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Inserting values
void enqueue(struct queue *q, int value){
    if(isFull(q)){
        printf("Queue is already full.\n");
    }
    else{
        q->rear ++;
        q->arr[q->rear] = value;
    }
}

// Deleting values
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("No element to dequeue.\n");
    }
    else{
        q->front ++;
        a = q->arr[q->front];                                                            
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 10;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 7);
    enqueue(&q, 5);
    enqueue(&q, 32);

    // Dequeue elements
    printf("Dequeue element is: %d\n", dequeue(&q));
    printf("Dequeue element is: %d\n", dequeue(&q));

    return 0;
}