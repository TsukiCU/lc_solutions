#include <stdio.h>

/* partition here divdes the
 *
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;

    for (int j=low; j<high; j++) {
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quick(int arr[], int low, int high) {
    if (low<high) {
        int pi = partition(arr, low, high);
        quick(arr, low, pi-1);
        quick(arr, pi+1, high);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 4, 2, 5, 3, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
