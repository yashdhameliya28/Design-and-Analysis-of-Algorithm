#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubbleSort(int arr[], int len){
    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int len){
    for(int i=0; i<len; i++){
        printf("%d\t", arr[i]);
    }
}

void main(){
    int len, userChoice;
    clock_t start, end;
    double  cpuTime;
    FILE *fp;

    printf("1.best case\n2.average case\n3.worst case\n");
    scanf("%d", &userChoice);

    switch (userChoice)
    {
    case 1:
        fp = fopen("../Case-File/best.txt", "r"); 
        break;
    
    case 2:
        fp = fopen("../Case-File/average.txt", "r"); 
        break;
    
    case 3:
        fp = fopen("../Case-File/worst.txt", "r"); 
        break;
    
    default:
        printf("Enter valid number!!!");
        break;
    }

    printf("Enter array length : ");
    scanf("%d", &len);

    int arr[len];

    for(int i=0; i<len; i++){  
        fscanf(fp, "%d", &arr[i]);
    }

    start = clock();
    bubbleSort(arr, len);
    end = clock();
    printArray(arr, len);

    cpuTime = (double) (end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken by bubble sort : %f", cpuTime);
}