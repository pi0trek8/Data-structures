//
// Created by Piotrek on 05/03/2023.
//

#ifndef LIST_LINKEDLIST_H
#define LIST_LINKEDLIST_H


#include "Node/Node.h"

class LinkedList {

    Node *head;

public:
    LinkedList();

    void printList();

    int get(int index);

    void push_front(int value);

    void push_back(int value);

    void add(int value, int index);

    void deleteNode(int index);

    void pop_back();

    void pop_front();

    int size();

    virtual ~LinkedList();

    void swap(int source, int destination);
};


#endif //LIST_LINKEDLIST_H
