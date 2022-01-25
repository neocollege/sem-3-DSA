#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
}

void bubbleSort(int arr[], int n){
    int shifts=0, swaps=0, comparisons=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swaps++;
            }
            comparisons++;
        }
    }
    printf("Swaps: %d\n",swaps);
    printf("Comparisons: %d\n",comparisons);
}

void modBubbleSort(int arr[], int n){
    int swaps=0,comparisons=0;
    for(int i=0; i<n; i++){
        int swapsx=0;
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapsx++;
                swaps+=swapsx;
            }
            comparisons++;
        }
        if(swapsx == 0)
            break;
    }
    printf("Swaps: %d\n",swaps);
    printf("Comparisons: %d\n",comparisons);
}

void selectionSort(int arr[], int n){
    int swaps=0, comparisons=0, min;
    for(int i=0; i<n; i++){
        min=i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min])
                min=j;
            comparisons++;
        }
        swap(&arr[i], &arr[min]);
        swaps++;
    }
    printf("Swaps: %d\n",swaps);
    printf("Comparisons: %d\n", comparisons);
}

void insertionSort(int arr[], int n){
    int key, swaps=0,comparisons=0;
    for(int i=1; i<n; i++){
        key = arr[i];
        int j=i-1;
        comparisons++;
        while(j>=0 & arr[j] > key){
            comparisons++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        swaps++;
    }
    printf("Swaps: %d\n",swaps);
    printf("Comparisons: %d\n",comparisons);
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void main(){
    int n, arr[20], ch;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    printf("Operations: \n1. Bubble Sort\n2. Modified Bubble Sort\n3. Selection Sort\n4. Insertion Sort\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            bubbleSort(arr, n);
            printArray(arr, n);
            break;
        case 2:
            modBubbleSort(arr, n);
            printArray(arr, n);
            break;
        case 3: 
            selectionSort(arr, n);
            printArray(arr, n);
            break;
        case 4:
            insertionSort(arr, n);
            printArray(arr, n);
            break;
        default: 
            printf("Enter a valid choice\n");
            break;
    }
}
