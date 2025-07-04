#include<stdio.h>
#include<time.h>

void linearsearch(int arr[], int len, int k){
    for(int i=0; i<len; i++){
        if(k == arr[i]){
            printf("Element found and element index is %d\n", i);
        }
    }
}

void main(){
    int len, k;
    FILE *fp;
    clock_t start, end;
    int arr[100000];

    fp = fopen("average.txt", "r");

    printf("Enter array lenght : ");
    scanf("%d", &len);

    printf("Enter a element to find : ");
    scanf("%d", &k);


    for(int i=0; i<len; i++){
        fscanf(fp, "%d", &arr[i]);
    }

    start = clock();
    linearsearch(arr, len, k);
    end = clock();

    double cpuTime = (double) ((end-start))/CLOCKS_PER_SEC;

    printf("Time taken by linear sort : %lf", cpuTime);
}