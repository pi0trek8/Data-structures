//
// Created by Piotr Szczypior on 07.03.2023.
//


#include <iostream>
#include <cmath>
#include "BinaryHeap.h"

using namespace std;

BinaryHeap::BinaryHeap() {
    _heap = nullptr;
    array_size = 0;
}

void BinaryHeap::heapify_down(int index) {
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    int largest = index;

    if (right_child_index < array_size && _heap[right_child_index] > _heap[largest]) {
        largest = right_child_index;
    }
    if (left_child_index < array_size && _heap[left_child_index] > _heap[largest]) {
        largest = left_child_index;
    }

    if (largest != index) {
        std::swap(_heap[index], _heap[largest]);
        heapify_down(largest);
    }
}

void BinaryHeap::heapify_up(int index) {
    int parent_index = (index - 1) / 2;

    if (index && _heap[index] > _heap[parent_index]) {
        std::swap(_heap[parent_index], _heap[index]);
        heapify_up(parent_index);
    }
}

void BinaryHeap::pop_front() {
    if (array_size == 0) {
        cout << "Heap is empty" << endl;
        return;
    }
    std::swap(_heap[0], _heap[array_size - 1]);

    int *temporaryArray = _heap;
    _heap = new int[--array_size];
    for (int i = 0; i < array_size; i++) {
        _heap[i] = temporaryArray[i + 1];
    }
    delete[] temporaryArray;

    heapify_down(0);
}

void BinaryHeap::push_back(int value) {
    if (_heap == nullptr) {
        _heap = new int[++array_size];
        _heap[0] = value;
        return;
    }
    int *temporaryArray = _heap;

    _heap = new int[++array_size];
    _heap[0] = value;

    for (int i = 1; i < array_size; i++) {
        _heap[i] = temporaryArray[i - 1];
    }

    delete[] temporaryArray;
    heapify_up(array_size - 1);
}

void BinaryHeap::print() {
    print("", 0, false);
}

void BinaryHeap::print(std::string prefix, int index, bool isLeft) {
    if (index < array_size) {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "|__");
        cout << _heap[index] << endl;

        print(prefix + (isLeft ? "|   " : "    "), 2 * index + 1, true);
        print(prefix + (isLeft ? "|   " : "    "), 2 * index + 2, false);

    }
}

std::string BinaryHeap::get_name() {
    return "Binary_Heap";
}

bool BinaryHeap::find_element(int element) {
    for (int i = 0; i < array_size - 1; i++) {
        if (_heap[i] == element) {
            return true;
        }
    }
    return false;
}

BinaryHeap::~BinaryHeap() {
    delete[] _heap;
}




