// used in case of sorted array
#include<stdio.h>

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size - 1;
    // keep searching until low converges with high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid] < element){
            low = mid + 1; // mid+1 bcz element not present at mid(checked previously)
        }
        else{
            high = mid - 1; // mid-1 bcz element not present at mid(checked previously)
        }
    }
    return -1;
}

int main(){
    int arr[] ={1, 3, 5, 11, 18, 23, 56, 80};
    int size = sizeof(arr)/sizeof(int);
    int element = 80;
    int searchIndex = binarySearch(arr, size, element);
    printf("Element is found at index %d.\n", searchIndex);

    return 0;
}