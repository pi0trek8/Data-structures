//
// Created by Piotr Szczypior on 07.03.2023.
//

#include <iostream>
#include "Array.h"
#include <string>

using namespace std;

Array::Array() {
    this->size = 0;
    this->data = nullptr;
}


void Array::print() {
    if (size == 0 || data == nullptr) {
        cout << "Array is empty" << endl;
        return;
    }
    // displaying structure element by element
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int Array::get_size() {
    return size;
}

void Array::insert(int value, int index) {
    if(size == 0) {
        push_front(value);
        return;
    }
    // check whether index is out of bound
    if (index < 0 || index > size) {
        cout << "Index out of bounds" << endl;
        return;
    }
    int *temporaryArray = new int[size + 1];
    // copying first half to memory block
    for (int i = 0; i < index; i++) {
        temporaryArray[i] = data[i];
    }
    //adding new value
    temporaryArray[index] = value;

    //copying rest of array
    for (int i = index + 1; i < size + 1; i++) {
        temporaryArray[i] = data[i - 1];
    }

    //increasing size and resolving previous memory block
    size++;
    delete[] data;
    data = temporaryArray;

}

void Array::push_front(int value) {
    //check if pointer has been initialize with 'new keyword
    if (data == nullptr) {
        data = new int[++size];
        data[0] = value;
        return;
    }
    int *temporaryArray = data;
    //initializing new memory block
    //copying all values with new one on the first index
    data = new int[++size];
    data[0] = value;

    for (int i = 1; i < size; i++) {
        data[i] = temporaryArray[i - 1];
    }

    delete[] temporaryArray;
}

void Array::push_back(int value) {
    if (data == nullptr) {
        data = new int[++size];
        data[0] = value;
        return;
    }
    int *temporaryArray = data;

    data = new int[++size];
    data[size - 1] = value;

    for (int i = 0; i < size - 1; i++) {
        data[i] = temporaryArray[i];
    }

    delete[] temporaryArray;
}

void Array::remove(int index) {
    // not initialized array
    if (data == nullptr) {
        cout << "Array is empty" << endl;
        return;
    }
    // out of bounds exception
    if (index < 0 || index > size) {
        cout << "Index out of bounds" << endl;
        return;
    }
    //sliding array in order to omit unwanted value
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }

    int *temporaryArray = data;
    //decreasing size and initializing new mem block
    data = new int[--size];

    //copying values to new smaller block
    for (int i = 0; i < size; i++) {
        data[i] = temporaryArray[i];
    }

    delete[] temporaryArray;
}

void Array::pop_back() {
    // if memory block has been initialized
    if (data == nullptr) {
        cout << "Array is empty" << endl;
        return;
    }
    int *temporaryArray = data;
    //decreasing size and removing last element by not copying it to new block
    data = new int[--size];
    for (int i = 0; i < size; i++) {
        data[i] = temporaryArray[i];
    }
    delete[] temporaryArray;
}

void Array::pop_front() {
    //if is initialized
    if (data == nullptr) {
        cout << "Array is empty" << endl;
        return;
    }
    int *temporaryArray = data;
    //decreasing size and removing first element by not copying it to new block
    data = new int[--size];
    for (int i = 0; i < size; i++) {
        data[i] = temporaryArray[i + 1];
    }
    delete[] temporaryArray;
}

void Array::swap(int source_index, int destination_index) {
    if (data == nullptr) {
        cout << "Array is empty" << endl;
        return;
    }
    if (source_index < 0 ||
        source_index >= size ||
        destination_index < 0 ||
        destination_index >= size) {
        cout << "Array out of bound exception !!!" << endl;
        return;
    }


    //swapping to values
    int temporaryValue = data[source_index];
    data[source_index] = data[destination_index];
    data[destination_index] = temporaryValue;
}

Array::~Array() {
    //resolving mem block
    delete[] data;
}

void Array::clear() {
    //removing memory block and reinitializing pointer
    delete[] data;
    data = nullptr;
    size = 0;
}

bool Array::find(int element) {
    // searching value in structure.
    for (int i = 0; i < size - 1; i++) {
        if (data[i] == element) {
            return true;
        }
    }
    return false;
}

int Array::get(int index) {
    // return element by index
    if (index < 0 || index >= size) {
        throw invalid_argument("index: " + to_string(index) + " is out of bounds for length: " + to_string(size));
    }
    return data[index];
}

string Array::get_name() {
    // utils method in order to distinguish structure object without reflection in C++
    return "Array";
}






