// By nature insertion sort is adaptive we don't have to do anything special like bubble sort(flag/isSorted) to make it adaptive
#include<stdio.h>

void printArray(int *arr, int length){
    printf("Array is:\n");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");
}

void insertionSort(int *arr, int length){
    for(int i = 1; i <= (length-1); i++){
        int key = arr[i];
        int j = i - 1;
        while(arr[j] > key && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {12, 45, 65, 7, 23, 9, 15};
    int length = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, length);
    insertionSort(arr, length);
    printArray(arr, length);

    return 0;
}