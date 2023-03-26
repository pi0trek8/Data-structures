//
// Created by Piotr Szczypior on 07.03.2023.
//


#include <iostream>
#include <cmath>
#include "BinaryHeap.h"

using namespace std;

void BinaryHeap::pop_back() {
    if (_heap.get_size() == 0) {
        cout << "Heap is empty" << endl;
        return;
    }
    _heap.swap(0, _heap.get_size() - 1);
    _heap.pop_back();
    heapify_down(0);

    //todo: after pop_back structure can be bad?
//    heapify_up(_heap.get_size() - 1);
}

void BinaryHeap::push_back(int value) {
    _heap.push_back(value);
    heapify_up(_heap.get_size() - 1);
}

int BinaryHeap::findElementByIndex() {
    return 0;
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

void BinaryHeap::push_front(int element) {

}

void BinaryHeap::insert(int element, int index) {

}

void BinaryHeap::remove(int index) {

}

void BinaryHeap::pop_front() {

}

void BinaryHeap::clear() {

}

int BinaryHeap::find(int element) {
    return 0;
}

std::string BinaryHeap::get_name() {
    return "Binary_Heap";
}



