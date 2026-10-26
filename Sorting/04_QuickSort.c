#include<stdio.h>

void printArray(int *arr, int length){
    printf("Array is:\n");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Finding the Index of pivotafter the partitioning process 
int partition(int *arr, int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do{
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i < j);

    // Swap arr[low] and arr[j]
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

// Quick Sort Algorithm
void quickSort(int *arr, int low, int high){
    int partitionIndex; // Index of pivot after partition
    if(low < high){
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1); // Sort left sub-array
        quickSort(arr, partitionIndex+1, high); // Sort right sub-array
    }
}

int main(){
    int arr[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int length = sizeof(arr) / sizeof(arr[0]);

    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 5, 2, 13i, 12, 3j, 2, 13, 45
    // 3, 5, 2, 3j, 12i, 13, 2, 13, 45 --> First call to partition return 3

    printArray(arr, length);
    quickSort(arr, 0, length-1);
    printArray(arr, length);

    return 0;
}