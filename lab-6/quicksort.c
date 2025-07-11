#include<stdio.h>
#include<time.h>

int pivot(int arr[], int lb, int ub){
    int pi = arr[lb];
    int k = lb;
    int l = ub + 1;

    do
    {
        k++;
    } while (arr[k] <= pi && k < ub);

    do
    {
        l--;
    } while (arr[l] > pi);
    
    while (k < l)
    {
        int temp = arr[k];
        arr[k] = arr[l];
        arr[l] = temp;

        do
        {
            k++;
        } while (arr[k] <= pi);

        do
        {
            l--;
        } while (arr[l] > pi);
    }

    int temp = arr[lb];
    arr[lb] = arr[l];
    arr[l] = temp;

    return l;
}

void quickSort(int arr[], int lb, int ub){
    if(lb < ub){
        int pi = pivot(arr, lb, ub);

        quickSort(arr, lb, pi-1);
        quickSort(arr, pi+1, ub);
    }
}

void printArray(int arr[], int length){
    for(int i=0; i<length; i++){
        printf("%d\t", arr[i]);
    }
}

void rearangeArray(int arr[], int i, int j){
    if(i < j){
        int mid = (i + j)/2;

        int temp = arr[i];
        arr[i] = arr[mid];
        arr[mid] = temp;

        rearangeArray(arr, i+1, mid);
        rearangeArray(arr, mid+1, j);
    }
}

int main(){
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

    printf("Enter number of element : ");
    scanf("%d", &len);


    for(int i=0; i<len; i++){
        fscanf(fp, "%d", &arr[i]);
    }

    int lb=0, ub=len-1;

    if(userChoice == 1){
        rearangeArray(arr, lb, ub);  
    }

    start = clock();
    quickSort(arr, lb, ub);
    end = clock();
    printArray(arr, len);

    double cpuTime = (double) ((end-start))/CLOCKS_PER_SEC;

    printf("\nTime taken by selection sort : %f", cpuTime);

}