#include<stdio.h>

void countingSort(int arr[], int sortedArr[], int max, int len){
    int c[max];
    for(int i=0; i<max; i++){
        c[i] = 0;
    }

    for(int j=0; j<max; j++){
        c[arr[j]] = c[arr[j]] + 1;
    }

    for(int i=2; i<max; i++){
        c[i] = c[i] + c[i-1];
    }

    for(int i=len-1; i>=0; i--){
        sortedArr[c[arr[i]]] = arr[i];
        c[arr[i]] = c[arr[i]] - 1;
    }
}

void printArray(int arr[], int len){
    for(int i=0; i<len; i++){
        printf("%d\t", arr[i]);
    }
}

void main(){
    int arr[9] = {3,6,4,1,3,4,1,4,2};
    int len = 9;
    int sortedArr[len];

    countingSort(arr, sortedArr, 6, len);
    printArray(sortedArr, len);
}