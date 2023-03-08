//
// Created by Piotr on 07.03.2023.
//

#ifndef LIST_BINARYHEAP_H
#define LIST_BINARYHEAP_H


#include <algorithm>
#include "../LinkedList/LinkedList.h"

class BinaryHeap {
private:
    LinkedList _heap;

    void heapify_down(int index) {
        int left_child_index = 2 * index + 1;
        int right_child_index = 2 * index + 2;
        int largest = index;

        if (left_child_index < _heap.size() && _heap.get(left_child_index) > _heap.get(largest)) {
            largest = left_child_index;
        }

        if (right_child_index < _heap.size() && _heap.get(right_child_index) > _heap.get(largest)) {
            largest = right_child_index;
        }

        if (largest != index) {
            _heap.swap(index, largest);
            heapify_down(largest);
        }
    }

    void heapify_up(int index) {
        int parent_index = (index - 1) / 2;

        if(index && _heap.get(index) > _heap.get(parent_index)) {
            _heap.swap(parent_index, index);
            heapify_up(parent_index);
        }
    }

    void print(std::string prefix, int value, bool isLeft);

public:

    void push(int value);

    void pop();

    int findElementByIndex();

    void print();
};


#endif //LIST_BINARYHEAP_H
