//
// Created by Piotr Szczypior on 07.03.2023.
//

#ifndef LIST_BINARYHEAP_H
#define LIST_BINARYHEAP_H


#include <algorithm>
#include "../DoubleList/DoubleList.h"
#include "../Array/Array.h"

class BinaryHeap : AbstractCollection {
private:
    DoubleList _heap;

    void heapify_down(int index) {
        int left_child_index = 2 * index + 1;
        int right_child_index = 2 * index + 2;
        int largest = index;

        if (right_child_index < _heap.get_size() && _heap.get(right_child_index) > _heap.get(largest)) {
            largest = right_child_index;
        }
        if (left_child_index < _heap.get_size() && _heap.get(left_child_index) > _heap.get(largest)) {
            largest = left_child_index;
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

    void push_back(int value) override;

    void pop_back() override;

    void push_front(int element) override;

    void insert(int element, int index) override;

    void remove(int index) override;

    void pop_front() override;

    void clear() override;

    int find(int element) override;

    int findElementByIndex();

    void print();

    void printHeap() {
        _heap.print();
    }
};


#endif //LIST_BINARYHEAP_H
