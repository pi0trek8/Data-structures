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

    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int Array::get_size() {
    return size;
}

void Array::insert( int value, int index) {
    if (index < 0 || index > size) {
        cout << "Index out of bounds" << endl;
        return;
    }
    int *temporaryArray = new int[size + 1];
    for (int i = 0; i < index; i++) {
        temporaryArray[i] = data[i];
    }
    temporaryArray[index] = value;
    for (int i = index + 1; i < size + 1; i++) {
        temporaryArray[i] = data[i - 1];
    }
    size++;
    delete[] data;
    data = temporaryArray;

}

void Array::push_front(int value) {
    if (data == nullptr) {
        data = new int[++size];
        data[0] = value;
        return;
    }
    int *temporaryArray = data;

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
    if (data == nullptr) {
        cout << "Array is empty" << endl;
        return;
    }

    if (index < 0 || index > size) {
        cout << "Index out of bounds" << endl;
        return;
    }

    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }

    int *temporaryArray = data;

    data = new int[--size];

    for (int i = 0; i < size; i++) {
        data[i] = temporaryArray[i];
    }

    delete[] temporaryArray;
}

void Array::pop_back() {
    if (data == nullptr) {
        cout << "Array is empty" << endl;
        return;
    }
    int *temporaryArray = data;

    data = new int[--size];
    for (int i = 0; i < size; i++) {
        data[i] = temporaryArray[i];
    }
    delete[] temporaryArray;
}

void Array::pop_front() {
    if (data == nullptr) {
        cout << "Array is empty" << endl;
        return;
    }
    int *temporaryArray = data;

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

    int temporaryValue = data[source_index];
    data[source_index] = data[destination_index];
    data[destination_index] = temporaryValue;
}

Array::~Array() {
    delete[] data;
}

void Array::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}

int Array::find(int element) {
    for(int i = 0; i < size - 1; i ++) {
        if(data[i] == element) {
            return i;
        }
    }
    return -1;
}

int Array::get(int index) {
    if (index < 0 || index >= size) {
        throw invalid_argument("index: " + to_string(index) + " is out of bounds for length: " + to_string(size));
    }
    return data[index];
}

string Array::get_name() {
    return "Array";
}






