#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include "BST.hpp"
#include "timerStartFinish.hpp"
#include <iostream> //used to print

template<typename TimeUnit, typename Id>
class Benchmark{
private:
    BST<Id, TimerStartFinish<TimeUnit>*> timers;

public:
    Benchmark(){}
    void startTimer(Id id){
        timers.insert(id, new TimerStartFinish<TimeUnit>());
        timers.getValue(id)->start();
    }
    void stopTimer(Id id){
        timers.getValue(id)->stop();
    }
    void printTime(Id id){
        std::cout << id << ": " << timers.getValue(id)->getTime().count() << "\n";
    }
};






#endif