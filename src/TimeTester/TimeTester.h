//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_TIMERTESTER_H
#define LIST_TIMERTESTER_H

#include "TimerTester.h"
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


template<class T>
void TimerTester::test_get(int collection_size, int test_count) {
    RandomGenerator random_generator;
    Timer timer;
    T collection;

    FileWriter file;
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
        auto duration = timer.elapsedTime();
        whole_time += duration;
        cout << test_number << " test is " << duration << endl;

        file.write_to_file(collection.get_name() + "_get_", collection_size, duration);
    }

    cout << "Average time of 'get' operation is: " << whole_time / test_count << endl;
}

template<class T>
void TimerTester::test_find(int collection_size, int test_count) {
    RandomGenerator random_generator;
    Timer timer;
    T collection;
    FileWriter file;
    auto whole_time = 0;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> random_value_distribution(-1000, 1000);

    for (int test_number = 0; test_number < test_count; test_number++) {
        int random_value = random_value_distribution(generator);

        collection = random_generator.fill_collection<T>(collection_size);

        timer.timeStart();
        collection.find(random_value);
        timer.timeStop();
        auto duration = timer.elapsedTime();
        whole_time += duration;
        cout << test_number << " test is " << duration << endl;

        file.write_to_file(collection.get_name() + "_find_", collection_size, duration);
    }

    cout << "Average time of 'find' operation is: " << whole_time / test_count << endl;
}

template<class T>
void TimerTester::test_remove(int collection_size, int test_count) {
    RandomGenerator random_generator;
    Timer timer;
    T collection;
    FileWriter file;
    auto whole_time = 0;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> random_index_distribution(0, collection_size - 1);

    for (int test_number = 0; test_number < test_count; test_number++) {
        int random_index = random_index_distribution(generator);

        collection = random_generator.fill_collection<T>(collection_size);

        timer.timeStart();
        collection.remove(random_index);
        timer.timeStop();
        auto duration = timer.elapsedTime();
        whole_time += duration;
        cout << test_number << " test is " << duration << endl;

        file.write_to_file(collection.get_name() + "_remove_", collection_size, duration);
    }

    cout << "Average time of 'remove' operation is: " << whole_time / test_count << endl;
}

template<class T>
void TimerTester::test_pop_front(int collection_size, int test_count) {
    RandomGenerator random_generator;
    Timer timer;
    T collection;
    FileWriter file;
    auto whole_time = 0;

    for (int test_number = 0; test_number < test_count; test_number++) {
        collection = random_generator.fill_collection<T>(collection_size);

        timer.timeStart();
        collection.find();
        timer.timeStop();
        auto duration = timer.elapsedTime();
        whole_time += duration;
        cout << test_number << " test is " << duration << endl;

        file.write_to_file(collection.get_name() + "_find_", collection_size, duration);
    }

    cout << "Average time of 'pop_front' operation is: " << whole_time / test_count << endl;
}

template<class T>
void TimerTester::test_pop_back(int collection_size, int test_count) {
    RandomGenerator random_generator;
    Timer timer;
    T collection;
    FileWriter file;
    auto whole_time = 0;

    for (int test_number = 0; test_number < test_count; test_number++) {
        collection = random_generator.fill_collection<T>(collection_size);

        timer.timeStart();
        collection.pop_back();
        timer.timeStop();
        auto duration = timer.elapsedTime();
        whole_time += duration;
        cout << test_number << " test is " << duration << endl;

        file.write_to_file(collection.get_name() + "_insert_", collection_size, duration);
    }

    cout << "Average time of 'pop_back' operation is: " << whole_time / test_count << endl;
}

template<class T>
void TimerTester::test_insert(int collection_size, int test_count) {
    RandomGenerator random_generator;
    Timer timer;
    T collection;
    FileWriter file;
    auto whole_time = 0;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> random_value_distribution(-1000, 1000);
    std::uniform_int_distribution<int> random_index_distribution(0, collection_size - 1);

    for (int test_number = 0; test_number < test_count; test_number++) {
        int random_value = random_value_distribution(generator);
        int random_index = random_index_distribution(generator);

        collection = random_generator.fill_collection<T>(collection_size);

        timer.timeStart();
        collection.insert(random_value, random_index);
        timer.timeStop();
        auto duration = timer.elapsedTime();
        whole_time += duration;
        cout << test_number << " test is " << duration << endl;

        file.write_to_file(collection.get_name() + "_insert_", collection_size, duration);
    }

    cout << "Average time of 'insert' operation is: " << whole_time / test_count << endl;
}

template<class T>
void TimerTester::test_push_front(int collection_size, int test_count) {
    RandomGenerator random_generator;
    Timer timer;
    T collection;
    FileWriter file;
    auto whole_time = 0;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> random_value_distribution(-1000, 1000);

    for (int test_number = 0; test_number < test_count; test_number++) {
        int random_value = random_value_distribution(generator);

        collection = random_generator.fill_collection<T>(collection_size);

        timer.timeStart();
        collection.push_front(random_value);
        timer.timeStop();
        auto duration = timer.elapsedTime();
        whole_time += duration;
        cout << test_number << " test is " << duration << endl;

        file.write_to_file(collection.get_name() + "_push_front_", collection_size, duration);
    }

    cout << "Average time of 'push_front' operation is: " << whole_time / test_count << endl;
}

template<class T>
void TimerTester::test_push_back(int collection_size, int test_count) {
    RandomGenerator random_generator;
    Timer timer;
    T collection;
    FileWriter file;
    auto whole_time = 0;
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> random_value_distribution(-1000, 1000);

    for (int test_number = 0; test_number < test_count; test_number++) {
        int random_value = random_value_distribution(generator);

        collection = random_generator.fill_collection<T>(collection_size);

        timer.timeStart();
        collection.push_back(random_value);
        timer.timeStop();
        auto duration = timer.elapsedTime();
        whole_time += duration;
        cout << test_number << " test is " << duration << endl;

        file.write_to_file(collection.get_name() + "_push_back_", collection_size, duration);
    }

    cout << "Average time of 'push_back' operation is: " << whole_time / test_count << endl;
}



#endif //LIST_TIMERTESTER_H
