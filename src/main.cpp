#include <iostream>     //used for output
#include <algorithm>    //used as comparison
#include "quicksort.hpp"
#include "containerTools.hpp"
#include "benchmark.hpp"

int main(){
    auto originalArray = ContainerTools::randomArray<float, 100000>(0,10000000000);
    Benchmark<std::chrono::nanoseconds, std::string> benchmark;

    auto ar = originalArray;

    benchmark.startTimer("   own");
    quicksort::arrayQuicksort(ar.begin(), ar.end());
    benchmark.stopTimer("   own");

    ar = originalArray;
    benchmark.startTimer("   std");
    std::sort(ar.begin(), ar.end());
    benchmark.stopTimer("   std");

    ar = originalArray;

    benchmark.startTimer("lambda");
    std::qsort(&ar[0], ar.size(), sizeof ar[0], [](const void* a, const void* b){
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);

        if(arg1 < arg2) return -1;
        if(arg1 > arg2) return 1;
        return 0;
    });
    benchmark.stopTimer("lambda");




    benchmark.printTime("   own");
    benchmark.printTime("   std");
    benchmark.printTime("lambda");



    return 0;
}
