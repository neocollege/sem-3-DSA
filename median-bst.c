#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * right;
    struct node * left;
};

struct node * createNode(int data){
    struct node * root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct node * insertNode(struct node * root, int data){
    if(root == NULL)
        return createNode(data);
    else if(root->data < data)
        root->right = insertNode(root->right, data);
    else if(root->data > data)
        root->left = insertNode(root->left, data);
    
    return root;
}

int cntNodes(struct node * root){
    struct node *curr, *pre;
    int cnt = 0;

    if(root == NULL)
        return cnt;

    curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            cnt++;
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                cnt++;
                curr = curr->right;
            }
        }
    } 
    return cnt;
}

int findMedian(struct node * root){
    if(root == NULL)
        return 0;
    
    int cnt = cntNodes(root);
    int currCnt = 0;
    struct node *curr = root, *pre, *prev;

    while(curr != NULL){
        if(curr->left == NULL){
            currCnt++;
            if(cnt%2 != 0 && currCnt == (cnt+1)/2)
                return curr->data;
            prev = curr;
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                prev = pre;
                currCnt++;
                if(cnt%2 != 0 && currCnt == (cnt+1)/2)
                    return curr->data;
                prev = curr;
                curr = curr->right;
            }
        }
    }
}

void main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    struct node * root = NULL;
    printf("Enter element: ");
    int temp;
    scanf("%d",&temp);
    root = insertNode(root, temp);
    for(int i=1; i<n; i++){
        printf("Enter element: ");
        scanf("%d",&temp);
        insertNode(root, temp);
    }
    printf("The median of the array is: %d",findMedian(root));
}      