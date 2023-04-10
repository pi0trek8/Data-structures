//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_TIMETESTERPPP_H
#define LIST_TIMETESTERPPP_H

#define UNIT nanoseconds

#include <random>
#include <chrono>
#include <iostream>


template<class T>
class TimeTesterppp {
public:
    static void make_test(int size, int test_count) {
        std::random_device randomDevice;
        std::mt19937 generator(randomDevice());
        std::uniform_int_distribution<int> random_value_distribution(-1000, 1000);
        std::uniform_int_distribution<int> random_index_distribution(0, size - 1);

        //time in microseconds
        long collection_push_front_duration = 0;
        long collection_push_back_duration = 0;
        long collection_insert_duration = 0;
        long collection_remove_duration = 0;
        long collection_remove_front_duration = 0;
        long collection_remove_back_duration = 0;
        long collection_find_duration = 0;

        for (int test_number = 0; test_number < test_count; test_number++) {

            int rand_array[size];
            for (int i = 0; i < size; i++) {
                rand_array[i] = random_value_distribution(generator);
            }
            T collection;
            for (int number: rand_array) {
                collection.push_back(number);
            }
            int random_element = random_value_distribution(generator);
            int random_index = random_index_distribution(generator);

            auto push_front_start = std::chrono::high_resolution_clock::now();
            collection.push_front(random_element);
            auto push_front_end = std::chrono::high_resolution_clock::now();
            auto push_front_duration = push_front_end - push_front_start;
            collection_push_front_duration += std::chrono::duration_cast<std::chrono::UNIT>(push_front_duration).count();

            auto remove_front_start = std::chrono::high_resolution_clock::now();
            collection.pop_front();
            auto remove_front_end = std::chrono::high_resolution_clock::now();
            auto remove_front_duration = remove_front_end - remove_front_start;
            collection_remove_front_duration += std::chrono::duration_cast<std::chrono::UNIT>(remove_front_duration).count();

            auto push_back_start = std::chrono::high_resolution_clock::now();
            collection.push_back(random_element);
            auto push_back_end = std::chrono::high_resolution_clock::now();
            auto push_back_duration = push_back_end - push_back_start;
            collection_push_back_duration += std::chrono::duration_cast<std::chrono::UNIT>(push_back_duration).count();

            auto remove_back_start = std::chrono::high_resolution_clock::now();
            collection.pop_front();
            auto remove_back_end = std::chrono::high_resolution_clock::now();
            auto remove_back_duration = remove_back_end - remove_back_start;
            collection_remove_back_duration += std::chrono::duration_cast<std::chrono::UNIT>(remove_back_duration).count();

            auto insert_start = std::chrono::high_resolution_clock::now();
            collection.insert(random_element, random_index);
            auto insert_end = std::chrono::high_resolution_clock::now();
            auto insert_duration = insert_end - insert_start;
            collection_insert_duration += std::chrono::duration_cast<std::chrono::UNIT>(insert_duration).count();

            auto remove_start = std::chrono::high_resolution_clock::now();
            collection.remove(random_index);
            auto remove_end = std::chrono::high_resolution_clock::now();
            auto remove_duration = remove_end - remove_start;
            collection_remove_duration += std::chrono::duration_cast<std::chrono::UNIT>(remove_duration).count();

            auto find_start = std::chrono::high_resolution_clock::now();
            collection.find(rand_array[random_index]);
            auto find_end = std::chrono::high_resolution_clock::now();
            auto find_duration = find_end - find_start;
            collection_find_duration += std::chrono::duration_cast<std::chrono::UNIT>(find_duration).count();
        }

        collection_push_front_duration /= test_count;
        collection_push_back_duration /= test_count;
        collection_insert_duration /= test_count;
        collection_remove_duration /= test_count;
        collection_remove_back_duration /= test_count;
        collection_remove_front_duration /= test_count;
        collection_find_duration /= test_count;

        std::cout << "push_front: " << collection_push_front_duration << std::endl;
        std::cout << "push_back: " << collection_push_back_duration << std::endl;
        std::cout << "insert: " << collection_insert_duration << std::endl;
        std::cout << "remove: " << collection_remove_duration << std::endl;
        std::cout << "remove_front: " << collection_remove_front_duration << std::endl;
        std::cout << "remove_back: " << collection_remove_back_duration << std::endl;
        std::cout << "find: " << collection_find_duration << std::endl;
    }
};


#endif //LIST_TIMETESTERPPP_H
