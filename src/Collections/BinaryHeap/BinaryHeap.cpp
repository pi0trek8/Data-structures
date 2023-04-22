//
// Created by Piotr Szczypior on 07.03.2023.
//


#include <iostream>
#include "BinaryHeap.h"

using namespace std;

void BinaryHeap::heapify_down(int index) {
    // assigning indexes based on the input
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;

    // assuming that the current node is the largest
    int largest = index;

    // check if the right child is larger than the current node
    if (right_child_index < _heap.get_size() && _heap.get(right_child_index) > _heap.get(largest)) {
        largest = right_child_index;
    }

    // check if the left child is larger than the current node (or the right child, if it was larger)
    if (left_child_index < _heap.get_size() && _heap.get(left_child_index) > _heap.get(largest)) {
        largest = left_child_index;
    }

    // if given index was not largest. Swap values and heapify down once more.
    if (largest != index) {
        _heap.swap(index, largest);
        heapify_down(largest);
    }
}

void BinaryHeap::heapify_up(int index) {
    // calculate index of parent
    int parent_index = (index - 1) / 2;

    // check if index is larger than 0 and if value of index position is grater than value of parent's position.
    if (index && _heap.get(index) > _heap.get(parent_index)) {
        // swap values and heapify up
        _heap.swap(parent_index, index);
        heapify_up(parent_index);
    }
}

void BinaryHeap::pop_front() {
    // check if array has been initialized (could be omitted because implemented array
    // already have this type of removing safe check but if this case was met without code below
    // it would print "array is empty" not "heap is empty"
    if (_heap.get_size() == 0) {
        cout << "Heap is empty" << endl;
        return;
    }
    // swap values
    _heap.swap(0, _heap.get_size() - 1);
    // remove last (after swap so in fact root) element
    _heap.pop_back();
    // repair
    heapify_down(0);
}

void BinaryHeap::push_back(int value) {
    // add new value to array
    _heap.push_back(value);
    // check whether everything sticks to maximum heap characteristics
    heapify_up(_heap.get_size() - 1);
}

void BinaryHeap::print() {
    // invoke print helper
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
    // utils method in order to distinguish
    // structure object without reflection in C++
    return "Binary_Heap";
}

bool BinaryHeap::find(int value) {
    // searching heap in order to find value
    // based on DRY principle the code would
    // be the same as in the array
    // because the solution is to simply iterate
    // throughout array
    return _heap.find(value);
}




