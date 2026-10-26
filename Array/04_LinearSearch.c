// used in case of both sorted and unsorted array
#include<stdio.h>

int linearSearch(int arr[], int size, int element){
    for(int i = 0; i<size; i++){
        if(element == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 3, 5, 56, 7, 23, 4, 34, 16};
    int size = sizeof(arr)/sizeof(int);
    int searchIndex = linearSearch(arr, size, 4);
    printf("Element is found at index %d.\n", searchIndex);

    return 0;
}