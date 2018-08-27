void benchStackArray(int arrSize, long long numOps) {
    int arr[arrSize];
    int tmp;
    for (register long long i = 0; i < numOps; ++i) {
        int elemIdx = i * i % arrSize;
        if (i % 2 == 0)
            tmp = arr[elemIdx];
        else
            arr[elemIdx] = tmp;
    }
}

void benchHeapArray(int arrSize, long long numOps) {
    int *arr = new int[arrSize];
    int tmp;
    for (register long long i = 0; i < numOps; ++i) {
        int elemIdx = i * i % arrSize;
        if (i % 2 == 0)
            tmp = arr[elemIdx];
        else
            arr[elemIdx] = tmp;
    }
    delete arr;
}
