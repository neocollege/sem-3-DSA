#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *st){
    return st->arr[st->top];
}

int isEmpty(struct stack *st){
    if(st->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *st){
    if(st->top == st->size - 1)
        return 1;
    else 
        return 0;
}

void push(struct stack *st, char val){
    if(isFull(st))
        printf("Stack Overflow! Cannot push %d to the satck\n", val);
    else{
        st->top++;
        st->arr[st->top] = val;
    }
}

char pop(struct stack *st){
    if(isEmpty(st)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = st->arr[st->top];
        st->top--;
        return val;
    }
}

int precedence(char ch){
    if(ch=='*' || ch=='/')
        return 3;
    else if(ch=='+' || ch=='-')
        return 2;
    else
        return 0;
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return 1;
    else 
    return 0;
}

char* infixToPostfix(char* infix){
    struct stack * st = (struct stack *) malloc(sizeof(struct stack));
    st->size = 10; 
    st->top = -1;
    st->arr = (char *) malloc(st->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(st))){
                push(st, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(st);
                j++;
            }
        }
    }
    while (!isEmpty(st)){
        postfix[j] = pop(st);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

void main(){
    char * infix;
    printf("Enter the infix operation: \n");
    scanf("%s",infix);
    printf("Postfix is: %s\n",infixToPostfix(infix));
}