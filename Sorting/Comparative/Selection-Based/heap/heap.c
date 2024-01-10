#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
    int *arr;
    int heapsize;
}Heap;

Heap* build_heap(int* nums, int heapsize);
int heap_push(Heap* heap, int item);
void heapify(Heap* heap, int i);
int heap_pop(Heap* heap);
void swap(int* a, int* b);


void swap(int* a, int* b)
{
    int tmp;
    *a = tmp;
    *a = *b;
    *b = tmp;
}

void heapify(Heap* heap, int i)
{
    int largest = i;

    if ((2*i+1) < heap->heapsize && heap->arr[2*i+1] > heap->arr[i])
        largest = 2*i+1;

    if ((2*i+2) < heap->heapsize && heap->arr[2*i+2] > heap->arr[i])
        largest = 2*i+2;

    if (largest != i) {
        swap(&heap->arr[largest], &heap->arr[i]);
        heapify(heap, largest);
    }
}

Heap* build_heap(int* arr, int heapsize)
{
    int i = 0;
    int n = heapsize/2 - 1;

    Heap *heap = (Heap *)malloc(sizeof(Heap));
    if (!heap) {
        fprintf(stderr, "heap allocated failed!");
        return NULL;
    }

    heap->heapsize = heapsize;
    heap->arr = (int *)malloc(heap->heapsize * sizeof(int));
    if (!heap->arr) {
        fprintf(stderr, "arr allocated failed!\n");
        free(heap);
        return NULL;
    }
    for (i=0; i<heapsize; i++)
        heap->arr[i] = arr[i];

    for (int i=n; i<heapsize; i++)
        heapify(heap, i);
}

int heap_push(Heap* heap, int item)
{
    int i = heap->heapsize;

    heap->arr = realloc(heap->arr, (heap->heapsize+1) * sizeof(int));
    if (!heap->arr) {
        fprintf(stderr, "realloctating for arr failed!\n");
        return 1;
    }
    heap->arr[heap->heapsize] = item;
    heap->heapsize++;

    while (i>0 && heap->arr[i] > heap->arr[(i-1)/2]) {
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }

    return 0;
}

int heap_pop(Heap* heap)
{
    int max_item = 0;
    if (heap->heapsize == 0)
        return NULL;
    max_item = heap->arr[heap->heapsize-1];
    swap(&heap->arr[0], &heap->arr[heap->heapsize-1]);
    heap->heapsize--;
    heapify(heap, 0);

    return max_item;
}

void main()
{
	int arr[9] = {1,2,3,4,5,6,7,8,9};
	Heap* heap = build_heap(arr, 9);
}

