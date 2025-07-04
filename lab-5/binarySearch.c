#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int min, int max, int k) {
    if (min <= max) {
        int mid = (min + max) / 2;
        if (arr[mid] == k) {
            return mid;
        } else if (arr[mid] < k) {
            return binarySearch(arr, mid + 1, max, k);
        } else {
            return binarySearch(arr, min, mid - 1, k);
        }
    }
    return -1;
}

int main() {
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
