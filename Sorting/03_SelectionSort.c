#include<stdio.h>

void printArray(int *arr, int length){
    printf("Array is:\n");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");
}

void selectionSort(int *arr, int length){
    for (int i = 0; i < (length-1); i++){
        int indexOfMin = i;
        for(int j = i+1; j < length; j++){
            if(arr[j] < arr[indexOfMin]){
               indexOfMin = j; 
            }
        }
        // swapping current index element with minimum element found in the array
        int temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp; 
    }
}

int main(){
    int arr[] = {12, 45, 65, 7, 23, 9, 15};
    int length = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, length);
    selectionSort(arr, length);
    printArray(arr, length);

    return 0;
}