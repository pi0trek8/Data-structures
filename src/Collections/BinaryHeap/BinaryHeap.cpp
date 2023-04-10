//
// Created by Piotr Szczypior on 07.03.2023.
//


#include <iostream>
#include "BinaryHeap.h"

using namespace std;

void BinaryHeap::heapify_down(int index) {
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

void BinaryHeap::heapify_up(int index) {
    int parent_index = (index - 1) / 2;

    if (index && _heap.get(index) > _heap.get(parent_index)) {
        _heap.swap(parent_index, index);
        heapify_up(parent_index);
    }
}

void BinaryHeap::pop_front() {
    if (_heap.get_size() == 0) {
        cout << "Heap is empty" << endl;
        return;
    }
    _heap.swap(0, _heap.get_size() - 1);
    _heap.pop_back();
    heapify_down(0);
}

void BinaryHeap::push_back(int value) {
    _heap.push_back(value);
    heapify_up(_heap.get_size() - 1);
}

void BinaryHeap::print() {
    print("", 0, false);
}

void BinaryHeap::print(std::string prefix, int index, bool isLeft) {
    if (index < _heap.get_size()) {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "|__");
        cout << _heap.get(index) << endl;

        print(prefix + (isLeft ? "|   " : "    "), 2 * index + 1, true);
        print(prefix + (isLeft ? "|   " : "    "), 2 * index + 2, false);

    }
}

std::string BinaryHeap::get_name() {
    return "Binary_Heap";
}

bool BinaryHeap::find_element(int value) {
    return _heap.find(value) != -1;
}




