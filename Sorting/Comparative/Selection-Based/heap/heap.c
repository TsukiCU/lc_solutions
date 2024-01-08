#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void heapify(int arr[], int heapsize, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if (left < heapsize && arr[largest] < arr[left])
        largest = left;

    if (right < heapsize && arr[largest] < arr[right])
        largest = right;

    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        heapify(arr, heapsize, largest);
    }
}

void heap(int arr[], int n)
{
    for (int i=n/2-1; i>=0; i--)
        heapify(arr, n, i);

    for (int i = n-1; i>=0; i--) {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    heap(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}