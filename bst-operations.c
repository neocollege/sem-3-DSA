#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
} node;

node * createNode(int data){
    node * root = (node *)malloc(sizeof(node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

node * insertNode(node * root, int data){
    if(root == NULL)
        return createNode(data);
    if(root->data < data)
        root->right = insertNode(root->right, data);
    else if(root->data > data)
        root->left = insertNode(root->left, data);
    
    return root;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int height(node * root){
    if(root == NULL)
        return 0;
    return max(height(root->left),height(root->left)) + 1;
}

node * lca(node * root, int a, int b){
    if(root == NULL)
        return NULL;
    
    if(root->data > a && root->data > b)
        return lca(root->left, a, b);
    
    if(root->data < a && root->data < b)
        return lca(root->right, a, b);
    
    return root;
}

node * kthSmallest(node * root, int *counter, int k){
    if(root != NULL){
        node * left = kthSmallest(root->left, counter, k);
        if(left != NULL)
            return left;
        
        if(++(*counter) == k)
            return root;
        
        return kthSmallest(root->right, counter, k);
    }
}

int isBalanced(node * root){
    if(root == NULL)
        return 1;
    
    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}

void printElements(node *root, int k1, int k2){
    if(root == NULL)
        return;
    
    if(k1 < root->data)
        printElements(root->left, k1, k2);

    if(k1 <= root->data && k2 >= root->data)
        printf("%d ", root->data);

    printElements(root->right, k1, k2);
}

node * bstInput(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    node * root = NULL;
    int temp;
    printf("Enter element: ");
    scanf("%d",&temp);
    root = insertNode(root, temp);
    for(int i=1; i<n; i++){
        printf("Enter element: ");
        scanf("%d",&temp);
        root = insertNode(root, temp);
    }
    return root;
}

void main(){
    node * root = bstInput();
    char ch;
    printf("a. lowest common ancestor of two nodes\nb. kth smallest element\nc. check if the bst is balanced or not\nd. print all elements in a given range\ne. exit\n");
    while(1>0){
        printf("Enter your choice: ");
        scanf(" %c",&ch);
        int a,b,k,k1,k2,counter = 0;
        switch(ch){
            case 'a':
                printf("Enter the two values: ");
                scanf("%d %d",&a,&b);
                node * lowest = lca(root, a, b);
                printf("LCA is %d\n", lowest->data);
                break;
            
            case 'b':
                printf("Enter k: ");
                scanf("%d",&k);
                printf("The kth smallest element is: %d\n",kthSmallest(root, &counter,  k)->data);
                break;
            
            case 'c':
                isBalanced(root)?printf("The BST is balanced\n"):printf("The BST is not balanced\n");
                break;
            
            case 'd':
                printf("Enter the boundaries: ");
                scanf("%d %d",&k1,&k2);
                printElements(root, k1, k2);
                printf("\n");
                break;

            case 'e':
                return;
                break;

            default: 
                printf("Enter a valid option.\n");
                break;
        }
    }
}