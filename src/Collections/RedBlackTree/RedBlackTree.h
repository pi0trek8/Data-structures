//
// Created by Piotr Szczypior on 03/04/2023.
//

#ifndef LIST_REDBLACKTREE_H
#define LIST_REDBLACKTREE_H

#include <string>
#include "node/Node.h"

using namespace std;

class RedBlackTree {
private:
    Node *_root;

    Node *get_uncle(Node *node);

    void rotate_left(Node *node_to_rotate);

    void rotate_right(Node *node_to_rotate);

    void balance_tree(Node *node);

    void print_helper(Node *node, std::string indent, bool isLast, bool isFirst);

    Node *delete_node(Node *node);

    void replace_child(Node *old_child, Node *new_child);

    Node *find_minimum(Node *node);

    void fix_delete(Node *node);

    Node *get_sibling(Node *node);

    bool is_black(Node *node);

public:

    RedBlackTree();

    void push_back(int value);

    void remove_element(int value);

    void print();

    bool find(int value);

    string get_name();
};


#endif //LIST_REDBLACKTREE_H
