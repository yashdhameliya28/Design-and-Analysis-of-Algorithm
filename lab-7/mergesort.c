#include <stdio.h>
#include<time.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;  
    int n2 = right - mid;     

    int L[n1], R[n2];  


    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];


    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }


    while (i < n1)
        arr[k++] = L[i++];


    while (j < n2)
        arr[k++] = R[j++];
}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;


        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);


        merge(arr, left, mid, right);
    }
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}


int main() {
    FILE *fp;
    clock_t start, end;
    int len, userChoice;
    int arr[100000];

    printf("1.best case\n2.worst case\n3.average case\n");
    scanf("%d", &userChoice);

    switch (userChoice)
    {
    case 1:
        fp = fopen("../Case-File/best.txt", "r");
        break;
    
    case 2:
        fp = fopen("../Case-File/worst.txt", "r");
        break;

    case 3:
        fp = fopen("../Case-File/average.txt", "r");
        break;
    
    default:
        printf("\nEnter valid number!!!");
        break;
    }

    // int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter number of element : ");
    scanf("%d", &len);


    for(int i=0; i<len; i++){
        fscanf(fp, "%d", &arr[i]);
    }

    start = clock();
    mergeSort(arr, 0, len - 1);
    end = clock();

    printArray(arr, len);

    double cpuTime = (double) ((end-start))/CLOCKS_PER_SEC;

    printf("\nTime taken by selection sort : %f", cpuTime);

    return 0;
}
