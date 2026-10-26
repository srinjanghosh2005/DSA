#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void printArray(int *arr, int length){
    printf("Array is:\n");
    for(int i = 0; i < length; i ++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximum(int *arr, int n){
    int max = INT_MIN;
    for(int i = 0; i < n; i ++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int *arr, int n){
    // Find the maximum element element in arr
    int max = maximum(arr, n);
    int *count = (int *)malloc((max + 1)*sizeof(int));
    // Initialize the array elements to 0
    for(int i = 0; i < max + 1; i ++){
        count[i] = 0;
    }

    // Increment the corresponding index in the count array
    for(int i = 0; i < n; i ++){
        count[arr[i]]++;
    }

    int i = 0; // Counter for count array
    int j = 0; // Counter for given array
    while(i < max + 1){
        if(count[i] > 0){
            arr[j] = i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    }
}

int main(){
    int arr[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;

    printArray(arr, n);
    countSort(arr, n);
    printArray(arr, n);
    
    return 0;
}