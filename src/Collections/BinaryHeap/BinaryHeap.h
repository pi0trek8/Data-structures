//
// Created by Piotr Szczypior on 07.03.2023.
//

#ifndef LIST_BINARYHEAP_H
#define LIST_BINARYHEAP_H


#include <algorithm>
#include "../Array/Array.h"

class BinaryHeap {
private:
    Array _heap;

    void heapify_down(int index);

    void heapify_up(int index);

    void print(std::string prefix, int value, bool isLeft);

public:

    void push_back(int value);

    void pop_front();

    bool find_element(int value);

    void print();

    std::string get_name();
};


#endif //LIST_BINARYHEAP_H
