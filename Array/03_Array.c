#include<stdio.h>

void display(int arr[], int size){
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deletion(int arr[], int size, int index){
    // Code for Deletion 
    for(int i = index; i<size-1; i++){
        arr[i] = arr[i+1];
    }
    printf("\n");
}

int main(){
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 1;
    display(arr, size);
    deletion(arr, size, index);
    size -=1;
    display(arr, size); 
    return 0;
}