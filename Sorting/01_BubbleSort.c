#include<stdio.h>

void printArray(int *arr, int length){
    printf("Array is:\n");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");
}

// Adaptive solution O(n)
void bubbleSort(int *brr, int length){
    int isSorted = 0;
    for(int i = 0; i < (length-1); i++){
        printf("Wroking on pass number %d\n", i+1);
        isSorted = 1;
        for(int j = 0; j < (length-i-1); j++){
            if(brr[j] > brr[j+1]){
                int temp = brr[j];
                brr[j] = brr[j+1];
                brr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
}


int main(){
    int arr[] = {12, 45, 65, 7, 23, 9, 15};
    int length = sizeof(arr) / sizeof(arr[0]);
    
    // Sorting first unsorted array
    printArray(arr, length);
    bubbleSort(arr, length);
    printArray(arr, length);
    
    int brr[] = {67, 74, 75, 87, 88, 99};
    int length2 = sizeof(brr) / sizeof(brr[0]);
    // Sorting second sorted array
    printArray(brr, length2);
    bubbleSort(brr, length2);
    printArray(brr, length2);

    return 0;
}