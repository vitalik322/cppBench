#include <vector>
#include <chrono>
#include <string>
#include <iostream>
#include <functional>

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

    funcNamePairs.push_back(make_pair(test, "my test func1"));
    funcNamePairs.push_back(make_pair(bind(benchPointerList, 100000), "Pointer-based linked list"));

    measureFuncs(funcNamePairs);

    return 0;
}
