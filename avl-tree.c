#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node * left;
    struct node * right;
    int height;
} node;

int getHeight(node * n){
    if(n == NULL)
        return 0;
    return n->height;
}

node *createNode(int key){
    node* n = (node *)malloc(sizeof(node));
    n->key = key;
    n->height = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int getBalanceFactor(node * n){
    if(n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

node *rightRotate(node *old){
    node *new = old->left;
    node *temp = new->right;

    new->right = old;
    old->left = temp;

    new->height = max(getHeight(new->right), getHeight(new->left)) + 1;
    old->height = max(getHeight(old->right), getHeight(old->left)) + 1;

    return new;
}

node *leftRotate(node *old){
    node *new = old->right;
    node *temp = new->left;

    new->left = old;
    old->right = temp;

    new->height = max(getHeight(new->right), getHeight(new->left)) + 1;
    old->height = max(getHeight(old->right), getHeight(old->left)) + 1;

    return new;
}

node * insertNode(node *n, int key){
    if(n == NULL)
        return(createNode(key));
    
    if(key < n->key)
        n->left = insertNode(n->left, key);
    else if(key > n->key)
        n->right = insertNode(n->right, key);
    
    n->height = max(getHeight(n->right), getHeight(n->left)) + 1;
    int bf = getBalanceFactor(n);

    //left left
    if(bf > 1 && key < n->left->key)
        return rightRotate(n);
    
    //right right
    if(bf < -1 && key > n->right->key)
        return leftRotate(n);

    //left right
    if(bf > 1 && key > n->left->key){
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    if(bf < -1 && key < n->right->key){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }

    return n;
}

void inOrder(struct node * root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->key);
        inOrder(root->right);
    }
}

void main(){
    int n;
    node * root = NULL;
    printf("Enter the number of nodes of the AVL tree: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int key;
        printf("Enter the element: ");
        scanf("%d",&key);
        root = insertNode(root, key);
    }
    inOrder(root);
}

