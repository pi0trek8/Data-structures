//
// Created by pszczypi on 07.03.2023.
//


#include <iostream>
#include <cmath>
#include "BinaryHeap.h"

using namespace std;

void BinaryHeap::pop() {
    if (_heap.size() == 0) {
        cout << "Heap is empty" << endl;
        return;
    }
    _heap.pop_front();
    heapify_down(0);
}

void BinaryHeap::push(int value) {
    _heap.push_back(value);
    heapify_up(_heap.size() - 1);
}

int BinaryHeap::findElementByIndex() {
    return 0;
}


void BinaryHeap::print() {
    print("", 0, false);
}

void BinaryHeap::print(std::string prefix, int index, bool isLeft) {
    if (index < _heap.size()) {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "|__");
        cout << _heap.get(index) << endl;

        print(prefix + (isLeft ? "|   " : "    "), 2 * index + 1, true);
        print(prefix + (isLeft ? "|   " : "    "), 2 * index + 2, false);
    }
}



