//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_TIMER_H
#define LIST_TIMER_H

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Timer {
public:
    high_resolution_clock::time_point initialTime;
    high_resolution_clock::time_point endTime;

    void timeStart();

    void timeStop();

    long elapsedTime() const;
};

void Timer::timeStart() {
    initialTime = high_resolution_clock::now();
}

void Timer::timeStop() {
    endTime = high_resolution_clock::now();
}

long Timer::elapsedTime() const {
    return duration_cast<nanoseconds>(endTime - initialTime).count();
}


#endif //LIST_TIMER_H
