//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_TIMERTESTER_H
#define LIST_TIMERTESTER_H

#include "TimerTester.h"
#include "RandomGenerator.h"
#include "Timer.h"

class TimerTester {

    template<class T>
    void test_push_back(int collection_size, int test_count);

    template<class T>
    void test_push_front(int collection_size, int test_count);

    template<class T>
    void test_insert(int collection_size, int test_count);

    template<class T>
    void test_pop_back(int collection_size, int test_count);

    template<class T>
    void test_pop_front(int collection_size, int test_count);

    template<class T>
    void test_remove(int collection_size, int test_count);

    template<class T>
    void test_find(int collection_size, int test_count);

public:
    template<class T>
    void test_get(int collection_size, int test_count);
};


template<class T>
void TimerTester::test_get(int collection_size, int test_count) {
    RandomGenerator random_generator;
    Timer timer;
    T collection;
    auto whole_time = 0;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> random_index_distribution(0, collection_size - 1);

    for (int test_number = 0; test_number < test_count; test_number++) {
        int random_index = random_index_distribution(generator);

        collection = random_generator.fill_collection<T>(collection_size);

        timer.timeStart();
        collection.get(random_index);
        timer.timeStop();
        auto push_front_duration = timer.elapsedTime();
        whole_time += push_front_duration;
        cout << test_number << " test is " << push_front_duration << endl;
    }

    cout << "Average time of 'get' operation is: " << whole_time/test_count << endl;
}

template<class T>
void TimerTester::test_find(int collection_size, int test_count) {

}

template<class T>
void TimerTester::test_remove(int collection_size, int test_count) {

}

template<class T>
void TimerTester::test_pop_front(int collection_size, int test_count) {

}

template<class T>
void TimerTester::test_pop_back(int collection_size, int test_count) {

}

template<class T>
void TimerTester::test_insert(int collection_size, int test_count) {

}

template<class T>
void TimerTester::test_push_front(int collection_size, int test_count) {

}

template<class T>
void TimerTester::test_push_back(int collection_size, int test_count) {

}

#endif //LIST_TIMERTESTER_H
