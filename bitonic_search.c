#include <stdio.h>
#include <stdlib.h>

int binaryAsc(int arr[], int l, int h, int key){
    while (l <= h){
        int mid = l + (h - l) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int binaryDesc(int arr[], int l, int h, int key){
    while (l <= h){
    int mid = l + (h - l) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        h = mid - 1;
    else
        l = mid + 1;
    }
    return -1;
}

int findBitonicPoint(int arr[], int n, int l, int r){
    int mid;
    int bitonicPoint = 0;
    mid = (r + l) / 2;
    if(mid < n-1){
        if (mid==0||arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
            bitonicPoint = findBitonicPoint(arr, n, mid+1, r);
        else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
            bitonicPoint = findBitonicPoint(arr, n, l, mid-1);
    }
    else if(mid == n-1){
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[0])
            return mid;
    }
    return bitonicPoint;
}

int searchBitonic(int arr[], int n, int key, int index){
    if (key > arr[index])
        return -1;
    else if (key == arr[index])
        return index;
    else{
        // Search in left of key
        int temp = binaryAsc(arr, 0, index - 1, key);
        if (temp != -1)
            return temp;
        // Search in right of key
        return binaryDesc(arr, index + 1, n - 1, key);
    }
}

int searchShiftPoint(int arr[], int index, int n){
    int k = -1;
    for (int i = index; i < n - 1; i++){
        if (arr[i] < arr[i + 1])
            return i;
    }
    return -1;
}

void main(){
    int n, key, index;
    printf("Enter number of elements of array: ");
    scanf("%d", &n);
    int arr[100];
    printf("Enter bitonic Array:\n");
    for (int i = 0; i < n; i++){
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }
    printf("Enter the number you want to search: ");
        scanf("%d", &key);
    // Function call
    index = findBitonicPoint(arr, n, 0, n - 1);
    int s = searchShiftPoint(arr, index + 1, n);
    if (s == -1){
        int x = searchBitonic(arr, n, key, index);
        if (x == -1)
            printf("Element Not Found\n");
        else
            printf("The element is present at index: %d \n", x);
    }
    else{
        int x = searchBitonic(arr, s + 1, key, index);
        if (x != -1)
            printf("The element is present at index: %d \n", x);
        else{
            int z = binaryAsc(arr, s + 1, n - 1, key);
            if (z == -1)
                printf("Element Not Found\n");
            else
                printf("The element is present at index: %d \n", z);
        }
    }
}