//
// Created by pszczypi on 09.03.2023.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H


class Node {
    int value;

public:
    explicit Node(int value);

    Node *next;
    Node *previous;
};


#endif //LIST_NODE_H
