#include <stdio.h>
#include <stdlib.h>

int heapSize = 0;
int n;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int isEmpty(){
    if(heapSize != 0)
        return 1;
    return 0;
}

int getParentIndex(int arr[], int index){
    int parentIndex = -1;
    if(index > 1 && index < n)
        parentIndex = index/2;
    return parentIndex;
}

void maxHeapify(int arr[], int index){
    int lchildIndex, rchildIndex, parentIndex;
    if((2*index)+1 < n){
        lchildIndex = (2*index);
        rchildIndex = (2*index)+1;
    }
    if(index > 1 && index < n)
        parentIndex = index/2;
    
    int largest = index;
    if(lchildIndex > 0 && lchildIndex <= heapSize)
        if(arr[lchildIndex] > arr[largest])
            largest = lchildIndex;
    if(rchildIndex > 0 && rchildIndex <= heapSize)
        if(arr[rchildIndex] > arr[largest])
            largest = rchildIndex;
    
    if(largest != index){
        swap(&arr[largest], &arr[index]);
        maxHeapify(arr, largest);
    }
}

void minHeapify(int arr[], int index){
    int lchildIndex, rchildIndex, parentIndex;
    if((2*index)+1 < n){
        lchildIndex = (2*index);
        rchildIndex = (2*index)+1;
    }
    if(index > 1 && index < n)
        parentIndex = index/2;
    int smallest = index;
    if(lchildIndex > 0 && lchildIndex <= heapSize)
        if(arr[lchildIndex] < arr[smallest])
            smallest = lchildIndex;
    if(rchildIndex > 0 && rchildIndex <= heapSize)
        if(arr[rchildIndex] < arr[smallest])
            smallest = rchildIndex;
    
    if(smallest != index){
        swap(&arr[smallest], &arr[index]);
        minHeapify(arr, smallest);
    }
}

void buildMaxHeap(int arr[]){
    for(int i = heapSize/2; i>=1; i--)
        maxHeapify(arr, i);
}

void buildMinHeap(int arr[]){
    for(int i = heapSize/2; i>=1; i--)
        minHeapify(arr, i);
}

int removeMax(int arr[]){
    int max = arr[1];
    arr[1] = arr[heapSize];
    heapSize--;
    maxHeapify(arr, 1);
    return max;
}

int removeMin(int arr[]){
    int min = arr[1];
    arr[1] = arr[heapSize];
    heapSize--;
    minHeapify(arr, 1);
    return min;
}

int getMax(int arr[]){
    return arr[1];
}

int getMin(int arr[]){
    return arr[1];
}

void increaseKeyMax(int arr[], int index, int key){
    arr[index] = key;
    while(index > 1 && arr[getParentIndex(arr, index)] < arr[index]){
        swap(&arr[index], &arr[getParentIndex(arr, index)]);
        index = getParentIndex(arr, index);
    }
}

void increaseKeyMin(int arr[], int index, int key){
    arr[index] = key;
    minHeapify(arr, index);
}

void decreaseKeyMin(int arr[], int index, int key){
    arr[index] = key;
    while(index > 1 && arr[getParentIndex(arr, index)] > arr[index]){
        swap(&arr[index], &arr[getParentIndex(arr, index)]);
        index = getParentIndex(arr, index);
    }
}

void decreaseKeyMax(int arr[], int index, int key){
    arr[index] = key;
    maxHeapify(arr, index);
}

void insertMax(int arr[], int key){
    heapSize++;
    increaseKeyMax(arr, heapSize, key);
}

void insertMin(int arr[], int key){
    heapSize++;
    decreaseKeyMin(arr, heapSize, key);
}

int removeFromMax(int arr[], int index){
    int bye = arr[index];
    arr[index] = arr[heapSize];
    heapSize--;
    maxHeapify(arr, index);
    return bye;
}

int removeFromMin(int arr[], int index){
    int bye = arr[index];
    arr[index] = arr[heapSize];
    heapSize--;
    minHeapify(arr, index);
    return bye;
}

void changeKeyMax(int arr[], int index, int key){
    if(key > arr[index])
        increaseKeyMax(arr, index, key);
    else
        decreaseKeyMax(arr, index, key);
}

void changeKeyMin(int arr[], int index, int key){
    if(key > arr[index])
        decreaseKeyMin(arr, index, key);
    else 
        increaseKeyMin(arr, index, key);
}

void printHeap(int arr[]){
    for(int i=1; i<=heapSize; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int size(){
    return heapSize;
}

void delRandomMax(int arr[]){
    //deletes a random element from the heap
    srand(time(0));
    int random = rand() % heapSize + 1;
    int removed = removeFromMax(arr, random);
    printf("Element removed: %d\n",removed);
}

void delRandomMin(int arr[]){
    srand(time(0));
    int random = rand() % heapSize + 1;
    int removed = removeFromMin(arr, random);
    printf("Element removed: %d\n",removed);
}

void mainMax(){
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    int arr[20];
    printf("Enter the priority queue: ");
    int key;
    for(int i=1; i<=n; i++){
        scanf("%d",&key);
        insertMax(arr, key);
    }
    printf("The heap is: ");
    printHeap(arr);
    int choice;
    printf("Enter the function you want to perform: \n1. Change Key\n2. Remove\n3. Remove Maximum\n4. Get Maximum\n5. Get size of the queue\n6. Delete random element\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    int i, k, max;
    switch(choice){
        case 1:
            //int i, k;
            printf("Enter the index of the element you want to change: ");
            scanf("%d", &i);
            printf("Enter key: ");
            scanf("%d", &k);
            changeKeyMax(arr, i, k);
            printf("The heap is: ");
            printHeap(arr);
            break;
        case 2:
            //int i;
            printf("Enter the index you want to remove from the heap: ");
            scanf("%d", &i);
            int removed = removeFromMax(arr, i);
            printf("The heap is: ");
            printHeap(arr);
            break;
        case 3: 
            //int max;
            max = removeMax(arr);
            printf("Maximum element (removed): %d\n",max);
            printf("The heap is: ");
            printHeap(arr);
            break;
        case 4:
            printf("Maximum is: %d",getMax(arr));
            break;
        case 5: 
            printf("Size of the priority queue is: %d",size());
            break;
        case 6: 
            delRandomMax(arr);
            printf("The heap is: ");
            printHeap(arr);
            break;
        default:
            printf("Enter a valid option.\n");
            mainMax();
            break;

    }
}

void mainMin(){
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    int arr[20];
    printf("Enter the priority queue: ");
    int key;
    for(int i=1; i<=n; i++){
        scanf("%d",&key);
        insertMin(arr, key);
    }
    printf("The heap is: ");
    printHeap(arr);
    int choice;
    printf("Enter the function you want to perform: \n1. Change Key\n2. Remove\n3. Remove Minimum\n 4. Get Minimum\n5. Get size of the queue\n6. Delete random element\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    int i, k, min;
    switch(choice){
        case 1:
            //int i, k;
            printf("Enter the index of the element you want to change: ");
            scanf("%d", &i);
            printf("Enter key: ");
            scanf("%d", &k);
            changeKeyMin(arr, i, k);
            printf("The heap is: ");
            printHeap(arr);
            break;
        case 2:
            //int i;
            printf("Enter the index you want to remove from the heap: ");
            scanf("%d", &i);
            int removed = removeFromMin(arr, i);
            printf("The heap is: ");
            printHeap(arr);
            break;
        case 3: 
            //int max;
            min = removeMin(arr);
            printf("Maximum element (removed): %d\n",min);
            printf("The heap is: ");
            printHeap(arr);
            break;
        case 4:
            printf("Maximum is: %d",getMin(arr));
            break;
        case 5: 
            printf("Size of the priority queue is: %d",size());
            break;
        case 6: 
            delRandomMin(arr);
            printf("The heap is: ");
            printHeap(arr);
            break;
        default:
            printf("Enter a valid option.\n");
            mainMin();
            break;
    }
}

void main(){
    char ch;
    printf("a. Max Priority Queue\nb. Min Priority Queue\nEnter your choice: ");
    scanf(" %c",&ch);
    switch(ch){
        case 'a':
            mainMax();
            break;
        case 'b':
            mainMin();
            break;
        default:
            printf("Enter a valid option.\n");
            main();
            break;
    }
}