#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = (high + low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main(){
    int len, k;
    FILE *fp;
    clock_t start, end;
    int arr[100000];

    fp = fopen("best.txt", "r");

    printf("Enter array length: ");
    scanf("%d", &len);

    printf("Enter an element to find: ");
    scanf("%d", &k);

    for (int i = 0; i < len; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    start = clock();
    int result = binarySearch(arr, 0, len - 1, k);
    end = clock();

    if (result == -1)
        printf("Element not found!!!\n");
    else
        printf("Element found and element index is %d\n", result);

    double cpuTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    printf("Time taken by binary search: %lf microseconds\n", cpuTime);

    return 0;
}
