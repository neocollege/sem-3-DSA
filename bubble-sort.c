#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int n){
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n){
    int temp;
    int isSorted = 1;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted)
            return;
    }
}

void main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[10];
    for(int i=0; i<n; i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    printArr(arr, n);
    bubbleSort(arr, n);
    printf("Sorted Array: ");
    printArr(arr,n);
}