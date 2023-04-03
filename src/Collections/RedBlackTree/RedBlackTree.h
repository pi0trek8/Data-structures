//
// Created by Piotr Szczypior on 03/04/2023.
//

#ifndef LIST_REDBLACKTREE_H
#define LIST_REDBLACKTREE_H


#include "node/Node.h"

class RedBlackTree {
private:
    Node* _root;

    void rotate_left(Node* node_to_rotate);

    void rotate_right(Node* node_to_rotate);

public:
    RedBlackTree();

    void push_back(int value);

    void remove(int value);

    void balance_tree(Node *node);
};


#endif //LIST_REDBLACKTREE_H
