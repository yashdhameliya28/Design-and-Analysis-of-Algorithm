#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int arr[], int len){
    int j, current;
    for(int i=1; i<len; i++){
        current = arr[i];
        j = i-1;

        while(j>=0 && current < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = current;
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
        fp = fopen("best.txt", "r"); 
        break;
    
    case 2:
        fp = fopen("average.txt", "r"); 
        break;
    
    case 3:
        fp = fopen("worst.txt", "r"); 
        break;
    
    default:
        printf("Enter valid number!!!");
        break;
    }
+
    printf("Enter array length : ");
    scanf("%d", &len);

    int arr[len];

    for(int i=0; i<len; i++){  
        fscanf(fp, "%d", &arr[i]);
    }

   start = clock();
    insertionSort(arr, len);
    end = clock();
    printArray(arr, len);

    cpuTime = (double) (end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken by bubble sort : %f", cpuTime);
}