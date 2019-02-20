#include <iostream>     //used for output
#include <array>        //to use quicksort on
#include <algorithm>    //used for comparing with self made implementation
#include <chrono>       //used for timing  
#include <thread>       //also used for timing
#include <random>       //used to generate random array

/*template<typename T>
void printStorage(const T & Storage){
    std::cout << "[ ";
    for(auto & x : Storage){
        std::cout << x << " ";
    }
    std::cout << "]\n";
}*/

template<typename T>
inline T* qsortMoving(T * begin, T * end){
    if (begin == end){
        return begin;
    }
    if(*begin > *end){
        T beginCHar = *(begin);
        *begin = *end;
        *end = *(begin+1);
        *(begin+1) = beginCHar;
        return qsortMoving(begin+1, end);
    }
    return qsortMoving(begin, end-1);
}

template<typename T>
inline void arrayQuicksort(T * begin, T * end){
    if( begin == end){
        return;
    }
    T* pivot = qsortMoving(begin, end-1);
    arrayQuicksort(begin, pivot);
    arrayQuicksort(pivot+1, end);
}

std::array<int, 100000>  bigRandomArray(){
    std::random_device rd;
    std::uniform_int_distribution<int> dist(INT32_MIN, INT32_MAX);
    std::array<int, 100000> ar;
    for(auto & i : ar){
        i = dist(rd);
    }
    return ar;
}


int main(){
    auto klok = std::chrono::steady_clock();
    
    auto ogArray = bigRandomArray();
    auto ar = ogArray;

    //printStorage(ar);
    auto before = klok.now();
    arrayQuicksort(ar.begin(), ar.end());
    auto after = klok.now();
    //printStorage(ar);
    std::cout << "own implementation: " << std::chrono::duration_cast<std::chrono::nanoseconds>(after-before).count() << "\n";
    
    ar = ogArray;

    before = klok.now();
    std::sort(ar.begin(), ar.end());
    after = klok.now();
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
    std::cout << "qso implementation: " << std::chrono::duration_cast<std::chrono::nanoseconds>(after-before).count() << "\n";


    std::string s;
    std::cin >> s;
    return 1;
}