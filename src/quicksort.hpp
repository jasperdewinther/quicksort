#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

namespace quicksort{
    template<typename T>
    T* _qsortMoving(T * begin, T * end){
        if (begin == end){
            return begin;
        }
        if(*begin > *end){
            T beginCHar = *(begin);
            *begin = *end;
            *end = *(begin+1);
            *(begin+1) = beginCHar;
            return _qsortMoving(begin+1, end);
        }
        return _qsortMoving(begin, end-1);
    }
    template<typename T>
    void arrayQuicksort(T * begin, T * end){
        if( begin == end){
            return;
        }
        T* pivot = _qsortMoving(begin, end-1);
        arrayQuicksort(begin, pivot);
        arrayQuicksort(pivot+1, end);
    }
};

#endif