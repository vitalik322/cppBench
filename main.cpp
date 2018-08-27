#include <vector>
#include <chrono>
#include <string>
#include <iostream>
#include <functional>

#include "hash/hash.h"
#include "stack/stack.h"
#include "arrayList/arrayList.h"
#include "stackHeap/stackHeap.h"
#include "pointerList/pointerList.h"

using namespace std;
using namespace std::chrono;

typedef vector<pair<function<void ()>, string>> vecFuncStrT;

void measureFuncs(vecFuncStrT& vecFuncName) {
    for (auto funcNamePair : vecFuncName) {
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        funcNamePair.first();
        high_resolution_clock::time_point t2 = high_resolution_clock::now(); 

        auto durationMs = duration_cast<milliseconds>( t2 - t1 ).count();
        std::cout << funcNamePair.second << ": " << durationMs << "ms" << endl;
    }
}

void test() {
    int topThresh = 300;
    for (int i1 = 0; i1 < topThresh; ++i1)
        for (int i2 = 0; i2 < topThresh; ++i2)
            for (int i3 = 0; i3 < topThresh; ++i3);
}

int main() {
    vecFuncStrT funcNamePairs;

    // Stack-heap array
    /*
    long long opsNum = 100000000;
    funcNamePairs.push_back(make_pair(bind(benchAllocStackArray, 1000000, opsNum), "Array allocated on stack"));
    funcNamePairs.push_back(make_pair(bind(benchAllocHeapArray, 1000000, opsNum), "Array allocated on heap"));
    // */

    // Lists
    /*
    funcNamePairs.push_back(make_pair(bind(benchPointerListFind, 50000), "Pointer-based linked list find method"));
    funcNamePairs.push_back(make_pair(bind(benchArrayListFind, 50000), "Array-based linked list find method"));
    funcNamePairs.push_back(make_pair(bind(benchPointerList, 20000), "Pointer-based linked list 400.000.000 insert/deletes"));
    funcNamePairs.push_back(make_pair(bind(benchArrayList, 20000), "Array-based linked list 400.000.000 insert/deletes"));
    // */

    // Stack
    //*
    funcNamePairs.push_back(make_pair(bind(benchStackList, 1000), "Array-based stack"));
    funcNamePairs.push_back(make_pair(bind(benchStackArray, 1000), "List-based stack"));
    // */

    // Hash table
    /*
    funcNamePairs.push_back(make_pair(bind(benchHashTableList, 250), "List hash table"));
    funcNamePairs.push_back(make_pair(bind(benchHashTableLinear, 250), "Linear hash table"));
    // */

    measureFuncs(funcNamePairs);

    return 0;
}
