#include <stdio.h>
#include <stdlib.h>

struct DEQueue{
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct DEQueue *dq){
    if(dq->f == -1 && dq->r == -1)
        return 1;
    else 
        return 0;
}

int isFull(struct DEQueue *dq){
    if((dq->f == 0 && dq->r == dq->size - 1) || dq->f == dq->r + 1)
        return 1;
    else 
        return 0;
}

void enqueueF(struct DEQueue *dq, int val){
    if(!isFull(dq)){
        if(dq->f == -1 && dq->r == -1){
            dq->f = dq->r = 0;
            dq->arr[dq->f] = val;
        }
        else if(dq->f == 0){
            dq->f = dq->size-1;
            dq->arr[dq->f] = val;
        }
        else{
            dq->f = dq->f-1;
            dq->arr[dq->f] = val;
        }
    }
    else
        printf("The Queue is full\n");
}

void enqueueR(struct DEQueue *dq, int val){
    if(!isFull(dq)){
        if(dq->f == -1 && dq->r == -1){
            dq->f = 0;
            dq->r = 0;
            dq->arr[dq->r] = val;
        }
        else if(dq->r == dq->size - 1){
            dq->r = 0;
            dq->arr[dq->r] = val;
        }
        else{
            dq->r = dq->r + 1;
            dq->arr[dq->r] = val;
        }
    }
    else
        printf("The Queue is empty\n");
}

void dequeueF(struct DEQueue *dq){
    int a = -1;
    if(!isEmpty(dq)){
        if(dq->f == dq->r){
            a = dq->arr[dq->f];
            dq->f = -1;
            dq->r = -1;
        }
        else if(dq->f == dq->size - 1){
            a = dq->arr[dq->f];
            dq->f = 0;
        }
        else{
            a = dq->arr[dq->f];
            dq->f = dq->f + 1;
        }
    }
}

void dequeueR(struct DEQueue *dq){
    int a = -1;
    if(!isEmpty(dq)){
        if(dq->f == dq->r){
            a = dq->arr[dq->r];
            dq->f = -1;
            dq->r = -1;
        }
        else if(dq->r == 0){
            a = dq->arr[dq->r];
            dq->r = dq->size -1;
        }
        else{
            a = dq->arr[dq->r];
            dq->r = dq->r - 1;
        }
    }
}

void max(int array[], int n, int k){
    struct DEQueue dq;
    dq.size = k;
    dq.f = -1;
    dq.r = -1;
    dq.arr = (int *)malloc(dq.size * sizeof(int));

    int i;
    for(i=0; i<k; ++i){
        while((!isEmpty(&dq)) && array[i] >= array[dq.r]){
            dequeueR(&dq);
        }
        enqueueR(&dq,i);
    }
    
    for(; i<n; ++i){
        printf("%d\t",array[dq.arr[dq.f]]);
        while(!isEmpty(&dq) && dq.arr[dq.f] <= i-k){
            dequeueF(&dq);
        }
        while(!isEmpty(&dq) && array[i] >= array[dq.arr[dq.r]]){
            dequeueR(&dq);
        }
        enqueueR(&dq, i);
    }

    printf("%d\t",array[dq.arr[dq.f]]);
}

void main(){
    int n=0;
    int k=0;
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    printf("Enter the size of the window: \n");
    scanf("%d",&k);
    int array[10];
    for(int i=0; i<n; i++){
        printf("Enter the element: \n");
        scanf("%d",&array[i]);
    }
    printf("\nMaximum elements of each window are:\n");
    max(array, n, k);
}