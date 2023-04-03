//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_DOUBLELISTNODE_H
#define LIST_NODE_H

#include "../Color.h"

class Node {
public:
    int value;
    Node *parent;
    Node *left_child;
    Node *right_child;
    Color color;

    explicit Node(int value);
};

#endif //LIST_DOUBLELISTNODE_H
