#include "allocation.h"

void benchAllocStackArray(int arrSize, long long numOps) {
    int arr[arrSize];
    int tmp = 322;
    for (register long long i = 0; i < numOps; ++i)
        arr[i * i % arrSize] = tmp;
    for (register long long i = 0; i < numOps; ++i)
        tmp = arr[i * i % arrSize];
}

void benchAllocHeapArray(int arrSize, long long numOps) {
    int *arr = new int[arrSize];
    int tmp = 322;
    for (register long long i = 0; i < numOps; ++i)
        arr[i * i % arrSize] = tmp;
    for (register long long i = 0; i < numOps; ++i)
        tmp = arr[i * i % arrSize];
    delete[] arr;
}

int arr[ARR_SIZE];
void benchAllocGlobalStackArray(int arrSize, long long numOps) {
    // assert(ARR_SIZE == arrSize);
    int tmp = 322;
    for (register long long i = 0; i < numOps; ++i)
        arr[i * i % arrSize] = tmp;
    for (register long long i = 0; i < numOps; ++i)
        tmp = arr[i * i % arrSize];
}

