//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_TIMETESTER_H
#define LIST_TIMETESTER_H

#include "TimeTester.h"
#include "RandomGenerator.h"
#include "Timer.h"
#include "../FileWriter/FileWriter.h"

class TimerTester {

public:
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

    template<class T>
    void test_get(int collection_size, int test_count);
};

#include "TimeTester.cpp"


#endif //LIST_TIMETESTER_H
