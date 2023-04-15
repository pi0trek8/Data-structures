//
// Created by Piotr Szczypior on 25/03/2023.
//

#include <random>

#ifndef LIST_RANDOMGENERATOR_H
#define LIST_RANDOMGENERATOR_H

#endif //LIST_RANDOMGENERATOR_H
using namespace std;

class RandomGenerator {
public:
    template<class T>
    T* fill_collection(int collection_size);
};

template<class T>
T* RandomGenerator::fill_collection(int collection_size) {
    random_device randomDevice;
    mt19937 generator(randomDevice());
    uniform_int_distribution<int> random_value_distribution(-1000000000, 1000000000);
    uniform_int_distribution<int> random_index_distribution(0, collection_size - 1);
    T *collection = new T();

    int rand_array[collection_size];
    for (int i = 0; i < collection_size; i++) {
        rand_array[i] = random_value_distribution(generator);
    }

    for(int number: rand_array) {
        collection->push_back(number);
    }

    return collection;
}
