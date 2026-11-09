// Circular Queue
#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct circularQueue *q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q){
    if((q->rear+1) % q->size == q->front){
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int value){
    if(isFull(q)){
        printf("Queue Overflow.\n");
    }
    else{
        printf("Enqueued element: %d\n", value);
        q->rear = (q->rear+1) % q->size;
        q->arr[q->rear] = value;
    }
}

int dequeue(struct circularQueue *q){
    int val = -1;
    if(isEmpty(q)){
        printf("Queue is empty.\n");
    }
    else{
        q->front = (q->front+1) % q->size;
        val = q->arr[q->front];
    }
    return val;
}

int main(){
    struct circularQueue q;
    q.size = 4;
    q.front = q.rear = 0; // 0 bcs if we put -1 then Queue is never gonna be full bcs "isFull" condition will never satisfy
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 7);
    enqueue(&q, 5);
    enqueue(&q, 32); // this enqueue is not possible bcs circular queue has size 4(so it can only take 3 elements)

    // Dequeue elements
    printf("Dequeue element is: %d\n", dequeue(&q));
    printf("Dequeue element is: %d\n", dequeue(&q));
    printf("Dequeue element is: %d\n", dequeue(&q));
    printf("Dequeue element is: %d\n", dequeue(&q)); // nothing to dequeue bcs queue is empty

    return 0;
}