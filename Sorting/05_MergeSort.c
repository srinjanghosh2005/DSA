#include<stdio.h>

void printArray(int *arr, int length){
    printf("Array is:\n");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int low, int mid, int high){
    // New auxilliary array size should be grater than (2 * size of given araay)
    int i, j, k, brr[15];
    i = low;
    j = mid+1;
    k = low;
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            brr[k] = arr[i];
            i++;
            k++;
        }
        else{
            brr[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        brr[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high){
        brr[k] = arr[j];
        j++;
        k++;
    }
    for(int i = 0; i <= high; i++){
        arr[i] = brr[i];
    }
}

void mergeSort(int *arr, int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    int arr[] = {3, 5, 2, 13, 12, 13, 45};
    int length = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, length);
    mergeSort(arr, 0, length-1);
    printArray(arr, length);

    return 0;
}