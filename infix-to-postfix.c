#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
struct stack{
    int size;
    int top;
    char *arr;
};
 
int stackTop(struct stack* st){
    return st->arr[st->top];
}
 
int isEmpty(struct stack *st){
    if (st->top == -1)
        return 1;
    else
        return 0;
}
 
int isFull(struct stack *st){
    if (st->top == st->size - 1)
        return 1;
    else
        return 0;
}
 
void push(struct stack* st, char val){
    if(isFull(st))
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    else
        st->top++;
        st->arr[st->top] = val;
}
 
char pop(struct stack* st){
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
    if(ch=='^')
        return 4;
    else if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}
 
int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/' || ch=='^') 
        return 1;
    else
        return 0;
}

char * infixToPostfix(char * infix){
    struct stack * st = (struct stack *)malloc(sizeof(struct stack));
    st->size = 20;
    st->top = -1;
    st-> arr = (char *)malloc(st->size * sizeof(char));
    char * postfix = (char *)malloc(strlen(infix)*sizeof(char *));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(isOperator(infix[i])){
            if(precedence(infix[i])>=precedence(stackTop(st))){
                push(st, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(st);
                j++;
            }
        }
        else if(infix[i] == '('){
            push(st, infix[i]);
            i++;
        }
        else if(infix[i] == ')'){
            while(!isEmpty(st) && stackTop(st)!='('){
                postfix[j] = pop(st);
                j++;
            }
            if(stackTop(st)=='('){
                i++;
            }
        }
        else{
                postfix[j] = infix[i];
                j++;
                i++;
        }
    }
    while(!isEmpty(st)){
        if(stackTop(st) == '(')
            pop(st);
        else{
            postfix[j] = pop(st);
            j++;
        }
    }
    postfix[j]='\0';
    return postfix;
}

int evalPostfix(char * postfix){
    struct stack * st = (struct stack *)malloc(sizeof(struct stack));
    st->size = 10;
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));
    for(int i=0;i<strlen(postfix);i++){
        if(!isOperator(postfix[i]))
            push(st,postfix[i] - '0');
        else{
            int op1 = pop(st);
            int op2 = pop(st);
            switch(postfix[i]){
                case '+': 
                    push(st,op2+op1);
                    break;
                case '-':
                    push(st,op2-op1);
                    break;
                case '*':
                    push(st,op2*op1);
                    break;
                case '/':
                    push(st,op2/op1);
                    break;
                case '^':
                    push(st,pow(op2,op1));
                    break;
                default:
                    printf("Invalid operator found.\n");
                    break;
            }
        }
    }
    return pop(st);
}

void main(){
    char * infix;
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    char * postfix = infixToPostfix(infix); 
    printf("Postfix is: %s\n", postfix);
    int result = evalPostfix(postfix);
    printf("Evaluated postfix expression is: %d\n", result);
}  

