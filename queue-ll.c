#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * link;
};

struct node * r = NULL;
struct node * f = NULL;

void traverse(struct node * n){
    printf("Printing the elements of this linked list: \n");
    while(n != NULL){
        if(n->link != NULL){
            printf("%d\t-->\t", n->data);
            n = n->link;
        }
        else{
            printf("%d\n", n->data);
            n = n->link;
        }
    }
}

void enqueue(int val){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if(n == NULL)
        printf("Queue is full\n");
    else{
        n->data = val;
        n->link = NULL;
        if(f == NULL)
            f = r = n;
        else{
            r->link = n;
            r = n;
        }
    }
}

int dequeue(){
    int val = -1;
    struct node * n = f;
    if(f==NULL)
        printf("Queue is empty\n");
    else{
        f = f->link;
        val = n->data;
        free(n);
    }
    return val;
}

void main(){
    //printf("Dequeuing element %d\n", dequeue());

    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    
    traverse(f);

    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());

    traverse(f);
}