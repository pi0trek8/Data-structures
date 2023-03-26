//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_DOUBLELISTNODE_H
#define LIST_NODE_H

#include "Color.h"

class DoubleListNode {
public:
    explicit DoubleListNode(int value);

    int value;
    DoubleListNode *parent;
    DoubleListNode *left_child;
    DoubleListNode *right_child;
    Color color;
};

#endif //LIST_DOUBLELISTNODE_H
