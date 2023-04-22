//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_ABSTRACTCOLLECTION_H
#define LIST_ABSTRACTCOLLECTION_H


class AbstractCollection {
public:
    virtual void push_back(int element) = 0;

    virtual void push_front(int element) = 0;

    virtual void insert(int element, int index) = 0;

    virtual void remove(int index) = 0;

    virtual void pop_front() = 0;

    virtual void pop_back() = 0;

    virtual void clear() = 0;

    virtual bool find(int element) = 0;

    virtual void print() = 0;
};


#endif //LIST_ABSTRACTCOLLECTION_H
