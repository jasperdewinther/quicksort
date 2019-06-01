#ifndef TIMERSTARTFINISH_HPP
#define TIMERSTARTFINISH_HPP

#include <chrono>       //used for timing

enum timerStates{
    READY,
    RECORDING,
    DONE,
    ADDRECORDING
};


template<typename TimeUnit>
class TimerStartFinish{
private:
    std::chrono::steady_clock m_clock;
    std::chrono::time_point<std::chrono::steady_clock> m_start;
    std::chrono::time_point<std::chrono::steady_clock> m_end;
    TimeUnit m_elapsedTime;
    timerStates m_state = timerStates::READY;

public:    
    TimerStartFinish(){}
    ~TimerStartFinish(){}
    void start(){
        if (m_state == timerStates::DONE){
            m_state = timerStates::ADDRECORDING;
        } else {
            m_state = timerStates::RECORDING;
        }
        m_start = m_clock.now();
    }
    void stop(){
        if (m_state == timerStates::RECORDING){
            m_end = m_clock.now();
            if (m_state == timerStates::ADDRECORDING){
                m_elapsedTime = std::chrono::duration_cast<TimeUnit>(m_end - m_start) + m_elapsedTime;
            } else {
                m_elapsedTime = std::chrono::duration_cast<TimeUnit>(m_end - m_start);
            }
            m_state = timerStates::DONE;            
        }
    }
    TimeUnit getTime(){
        if (m_state == timerStates::DONE){
            return m_elapsedTime;
        }
        throw "clock not ended\n";
        return std::chrono::duration_cast<TimeUnit>(m_clock.now() - m_clock.now());
    }
    void reset(){
        this = TimerStartFinish();
    }
};







#endif