//
// Created by Piotr Szczypior on 07.03.2023.
//

#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H


#include "../AbstractCollection.h"
#include <string>

using namespace std;

class Array : public AbstractCollection {
    int *data;
    int size;

public:
    Array();

    void insert(int value, int index) override;

    void push_front(int value) override;

    void push_back(int value) override;

    void print() override;

    int get_size();

    void remove(int index) override;

    void pop_back() override;

    void pop_front() override;

    void clear() override;

    int get(int index);

    int find(int element) override;

    void swap(int source_index, int destination_index);

    string get_name();

    virtual ~Array();
};


#endif //LIST_ARRAY_H
