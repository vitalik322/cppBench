void benchWithAddressArith(int arrSize, int numIters) {
    register int *arr1 = new int[arrSize];
    register int *arr2 = new int[arrSize];
    int *finishAddr = arr1 + arrSize;
    for (register int i = 0; i < numIters; ++i)
        for (register int *a1 = arr1, *a2 = arr2; a1 < finishAddr; ++a1, ++a2)
            *a2 = *a1;
    delete[] arr1;
    delete[] arr2;
}

void benchWithoutAddressArith(int arrSize, int numIters) {
    register int *arr1 = new int[arrSize];
    register int *arr2 = new int[arrSize];
    for (register int i = 0; i < numIters; ++i)
        for (register int j = 0; j < arrSize; ++j)
            arr1[j] = arr2[j];
    delete[] arr1;
    delete[] arr2;
}
