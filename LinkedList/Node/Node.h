//
// Created by Piotrek on 05/03/2023.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H


class Node {

public:
    Node();

    Node(int value);

    Node* next_node;
    int value;
};


#endif //LIST_NODE_H
