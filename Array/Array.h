//
// Created by pszczypi on 07.03.2023.
//

#ifndef LIST_ARRAY_H
#define LIST_ARRAY_H


class Array {
    int* data = nullptr;
    int size = 0;

public:
    Array();

    void add(int index, int value);

    void push_front(int value);

    void push_back(int value);

    void print();

    int getSize();

    void deleteIndex(int index);

    void pop_back();

    void pop_front();

    virtual ~Array();
};


#endif //LIST_ARRAY_H
