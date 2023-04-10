#include "Timer.h"

void Timer::timeStart() {
    initialTime = high_resolution_clock::now();
}

void Timer::timeStop() {
    endTime = high_resolution_clock::now();
}

long Timer::elapsedTime() {
    return duration_cast<nanoseconds>(endTime - initialTime).count();
}