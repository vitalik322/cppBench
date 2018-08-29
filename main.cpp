#include <vector>
#include <chrono>
#include <string>
#include <cassert>
#include <iostream>
#include <functional>

#include "hash/hash.h"
#include "stack/stack.h"
#include "register/register.h"
#include "arrayList/arrayList.h"
#include "allocation/allocation.h"
#include "pointerList/pointerList.h"
#include "addressArithmetic/addressArithmetic.h"

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

void testLists() {
    std::cout << "testing lists" << std::endl;
    ArrayLinkedList arrayList;
    PointerLinkedList pointerList;
    for (register int i = 0; i < 1000; ++i) {
        int randNum = rand() % 1000;

        if (pointerList.find(randNum) == nullptr)
            assert(arrayList.find(randNum) == nullptr);
        else
            assert(pointerList.find(randNum)->value == arrayList.find(randNum)->value);

        if (arrayList.find(randNum) != nullptr) {  // if num exists - insert new one, or remove
            if (rand() % 2) {  // insert
                int newValue = rand() % 1000;
                arrayList.insertAfter(arrayList.find(randNum), newValue);
                pointerList.insertAfter(pointerList.find(randNum), newValue);
            }
            else {  // remove
                arrayList.remove(arrayList.find(randNum));
                pointerList.remove(pointerList.find(randNum));
            }
        }
        else {  // if num doesn't exist - insert new one
            arrayList.insertAfter(arrayList.root_, randNum);
            pointerList.insertAfter(pointerList.root_, randNum);
        }
    }
    std::cout << "ok" << std::endl;
}

int main() {
    vecFuncStrT funcNamePairs;

    // 'register' keyword
    /*
    funcNamePairs.push_back(make_pair(bind(benchWithRegister, 2000), "with register"));
    funcNamePairs.push_back(make_pair(bind(benchWithoutRegister, 2000), "without register"));
    // */

    // address arithmetic
    /*
    funcNamePairs.push_back(make_pair(bind(benchWithAddressArith, 1000000, 20000), "with address arithmetic"));
    funcNamePairs.push_back(make_pair(bind(benchWithoutAddressArith, 1000000, 20000), "without address arithmetic"));
    // */

    // Array access
    /*
    long long opsNum = 1000000000;
    funcNamePairs.push_back(make_pair(bind(benchAllocStackArray, 1000000, opsNum), "Array allocated on stack"));
    funcNamePairs.push_back(make_pair(bind(benchAllocHeapArray, 1000000, opsNum), "Array allocated on heap"));
    funcNamePairs.push_back(make_pair(bind(benchAllocGlobalStackArray, 1000000, opsNum), "Array allocated on global stack"));
    // */

    // Lists
    //*
    testLists();
    funcNamePairs.push_back(make_pair(bind(benchPointerListFind, 80000), "Pointer-based linked list find method"));
    funcNamePairs.push_back(make_pair(bind(benchArrayListFind, 80000), "Array-based linked list find method"));
    //funcNamePairs.push_back(make_pair(bind(benchPointerList, 20000), "Pointer-based linked list 400.000.000 insert/deletes"));
    //funcNamePairs.push_back(make_pair(bind(benchArrayList, 20000), "Array-based linked list 400.000.000 insert/deletes"));
    // */

    // Stack
    /*
    funcNamePairs.push_back(make_pair(bind(benchStackArray, 5000), "Array-based stack"));
    funcNamePairs.push_back(make_pair(bind(benchStackList, 5000), "List-based stack"));
    // */

    // Recursion + Stack
    /*
    funcNamePairs.push_back(make_pair(bind(benchFacRec, 500, 10000), "Recursive facrotial"));
    funcNamePairs.push_back(make_pair(bind(benchFacStack, 500, 10000), "Stack-based factorial"));
    // */

    // Hash table
    /*
    funcNamePairs.push_back(make_pair(bind(benchHashTableList, 250), "List hash table"));
    funcNamePairs.push_back(make_pair(bind(benchHashTableLinear, 250), "Linear hash table"));
    // */

    measureFuncs(funcNamePairs);

    return 0;
}
