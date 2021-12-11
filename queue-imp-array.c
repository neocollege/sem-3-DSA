#include <stdio.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if(q->r == q->size - 1)
        return 1;
    else 
        return 0;
}

int isEmpty(struct queue *q){
    if(q->r == q->f)
        return 1;
    else 
        return 0;
}

void enqueue(struct queue *q, int val){
    if(!isFull(q)){
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued Element: %d\n",val);
    }
    else{
        printf("The queue is full\n");
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(!isEmpty(q)){
        q->f++;
        a = q->arr[q->f];
    }
    else
        printf("The queue is empty\n");
    return a;
}

void main(){
    struct queue * q;
    q->size = 4;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
 
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
}
