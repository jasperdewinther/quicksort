#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <random>
#include <climits>
#include <sys/resource.h>


template<typename T>
void printStorage(const T & Storage){
    std::cout << "[ ";
    for(auto & x : Storage){
        std::cout << x << " ";
    }
    std::cout << "]\n";
}

template<typename T>
inline void threeWaySwap(T & first, T & second, T & third){
    std::swap(first, second);
    std::swap(first, third);
}

template<typename T>
inline T* qsortMoving(T * begin, T * end){
    if (begin == end){
        return begin;
    }
    int counter = 0;
    while(counter != end-begin){
        std::cout << *(begin+counter) << ',';
        counter ++;
    }
    std::cout << *(begin+counter) << ',' << '\n';
    if(*begin > *end){
        /*T firstChar = *begin;
        *begin = *(end-1);
        *(end-1) = *end;
        *end = firstChar;*/
        threeWaySwap(*end, *(end-1), *begin);
        return qsortMoving(begin, end-1);
    }
    return qsortMoving(begin+1, end);
}

template<typename T>
inline void quicksort(T * begin, T * end){
    if( begin == end){
        return;
    }
    T* pivot = qsortMoving(begin, end-1);
    quicksort(begin, pivot);
    quicksort(pivot+1, end);
}

std::array<int, 5>  bigRandomArray(){
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 100);
    std::array<int, 5> ar;
    for(auto & i : ar){
        i = dist(rd);
    }
    return ar;
}


int main(){
    auto klok = std::chrono::steady_clock();
    
    auto ogArray = bigRandomArray();
    auto ar = ogArray;

    printStorage(ar);
    auto before = klok.now();
    quicksort(ar.begin(), ar.end());
    auto after = klok.now();
    printStorage(ar);
    std::cout << "own implementation: " << std::chrono::duration_cast<std::chrono::nanoseconds>(after-before).count() << "\n";
    
    ar = ogArray;

    before = klok.now();
    std::sort(ar.begin(), ar.end());
    after = klok.now();
    //printStorage(ar);
    std::cout << "std implementation: " << std::chrono::duration_cast<std::chrono::nanoseconds>(after-before).count() << "\n";

    ar = ogArray;
    before = klok.now();
    std::qsort(&ar[0], ar.size(), sizeof ar[0], [](const void* a, const void* b){
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);
        
        if(arg1 < arg2) return -1;
        if(arg1 > arg2) return 1;
        return 0;
    });
    after = klok.now();
    //printStorage(ar);
    std::cout << "qso implementation: " << std::chrono::duration_cast<std::chrono::nanoseconds>(after-before).count() << "\n";


    std::string s;
    std::cin >> s;
    return 1;
}