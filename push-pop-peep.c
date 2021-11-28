#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr, int val){
    if(isFull(ptr))
        printf("Stack Overflow! Cannot push %d to the stack\n");
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i){
    int arrayInd = ptr->top - i + 1;
    if(arrayInd<0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
        return ptr->arr[arrayInd];
}

void main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter size of stack\n");
    scanf("%d",&sp->size);
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    for(int i=0;i<sp->size;i++){
        int val;
        printf("Enter value: \n");
        scanf("%d",&val);
        for(int i=0;i<sp->size;i++)
            push(sp, val);
    }
    printf("Stack has been created successfully.");
    pop(sp);
    pop(sp);
    int i;
    printf("Enter the value you want to peek: \n");
    scanf("%d",&i);
    printf("The value at position %d is %d", i, peek(sp, i));
}