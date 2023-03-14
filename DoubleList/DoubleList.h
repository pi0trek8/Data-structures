//
// Created by pszczypi on 09.03.2023.
//

#ifndef LIST_DOUBLELIST_H
#define LIST_DOUBLELIST_H


#include "Node.h"

class DoubleList {

private:
    Node *head;

public:
    void push_front(int value);

//    Node* find(int value);

    void deleteValue(int value);
};


#endif //LIST_DOUBLELIST_H
