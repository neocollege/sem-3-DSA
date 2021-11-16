#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *create(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data for new node: ");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return(newnode);
}

struct node *create_with_value(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=NULL;
    return(newnode);
}

struct node *insert_end(struct node *lhead){
    struct node *temp, *ptr;
    temp = create();
    if(lhead==NULL)
        lhead=temp;
    else{
        ptr=lhead;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=temp;
    }
    return(lhead);
}

struct node *insert_at_position(struct node *lhead, int posn, int value){
    struct node *newnode, *ptr, *temp;
    void traverse(struct node *); 
    temp=lhead;
    printf("\n%d    %d",posn,value);
    newnode = create_with_value(value);
    if(lhead==NULL)
        lhead=newnode;
    else if(posn==1){
        newnode->link=lhead;
        lhead=newnode;
    }
    else{
        ptr=lhead;
        for(int i=1;i<posn-1;i++)
            ptr=ptr->link;
        newnode->link=ptr->link;
        ptr->link=newnode;
    }
    traverse(lhead);
    return(lhead);
}

void traverse(struct node *lhead){
    struct node *temp;
    if(lhead==NULL)
        printf("\nList is empty");
    else{
        printf("\nList is: ");
        temp=lhead;
        while(temp!=NULL){
            printf("\t%d-->",temp->data);
            temp=temp->link;
        }
    }
}

void main(){
    int i,posn,data;
    struct node *head=NULL;
    printf("Linked List Creation and Display");
    for(i=0;i<5;i++)
        head=insert_end(head);
    traverse(head);
    printf("\nEnter the position at which you want to enter new node: ");
    scanf("%d",&posn);
    printf("Enter the value of the new node: ");
    scanf("%d",&data);
    head=insert_at_position(head,posn,data);
    traverse(head);
}