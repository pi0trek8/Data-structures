//
// Created by Piotr Szczpior on 09.03.2023.
//

#ifndef LIST_DOUBLELIST_H
#define LIST_DOUBLELIST_H

#include <string>
#include "../AbstractCollection.h"
#include "Node/DoubleListNode.h"

using namespace std;

class DoubleList : public AbstractCollection {

private:
    DoubleListNode *head = nullptr;
    DoubleListNode *tail = nullptr;
    int list_size = 0;

public:
    void push_back(int element) override;

    void push_front(int element) override;

    void insert(int element, int index) override;

    void remove(int index) override;

    void pop_front() override;

    void pop_back() override;

    void clear() override;

    int find(int element) override;

    void print() override;

    int get_size();

    void swap(int first_index, int second_index);

    int get(int index);

    static string get_name();
};


#endif //LIST_DOUBLELIST_H
