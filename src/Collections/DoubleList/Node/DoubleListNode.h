//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_DOUBLELISTNODE_H
#define LIST_DOUBLELISTNODE_H


class DoubleListNode {
public:
    DoubleListNode(int value);

    DoubleListNode();

    int value;
    DoubleListNode *previous_node;
    DoubleListNode *next_node;
};


#endif //LIST_DOUBLELISTNODE_H
