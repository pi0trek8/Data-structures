//
// Created by Piotr Szczypior on 03/04/2023.
//

#include "RedBlackTree.h"
#include <iostream>

using namespace std;

RedBlackTree::RedBlackTree() {
    this->_root = nullptr;
}

void RedBlackTree::rotate_right(Node *node_to_rotate) {
    Node *node_to_rotate_parent = node_to_rotate->parent;
    node_to_rotate_parent->left_child = node_to_rotate->right_child;

    if (node_to_rotate_parent->left_child != nullptr) {
        node_to_rotate_parent->left_child->parent = node_to_rotate_parent;
    }

    node_to_rotate->parent = node_to_rotate_parent->parent;

    if (node_to_rotate_parent->parent == nullptr) {
        _root = node_to_rotate;
    } else if (node_to_rotate_parent == node_to_rotate_parent->parent->left_child) {
        node_to_rotate_parent->parent->left_child = node_to_rotate;
    } else {
        node_to_rotate_parent->parent->right_child = node_to_rotate;
    }

    node_to_rotate->right_child = node_to_rotate_parent;
    node_to_rotate_parent->parent = node_to_rotate;
}

void RedBlackTree::rotate_left(Node *node_to_rotate) {
    auto node_to_rotate_parent = node_to_rotate->parent;
    node_to_rotate_parent->right_child = node_to_rotate->left_child;

    if (node_to_rotate->left_child != nullptr) {
        node_to_rotate->left_child->parent = node_to_rotate_parent;
    }

    if (node_to_rotate_parent->parent == nullptr) {
        _root = node_to_rotate;
    } else if (node_to_rotate_parent->parent->left_child == node_to_rotate_parent) {
        node_to_rotate_parent->parent->left_child = node_to_rotate;
    } else {
        node_to_rotate_parent->parent->right_child = node_to_rotate;
    }

    node_to_rotate_parent->parent = node_to_rotate;
    node_to_rotate->left_child = node_to_rotate_parent;
}

void RedBlackTree::balance_tree(Node *node) {

}

void RedBlackTree::push_back(int value) {
    Node *new_node = new Node(value);
    Node *temporary_node = _root;
    Node *previous_to_temporary_node = nullptr;

    while (temporary_node != nullptr) {
        previous_to_temporary_node = temporary_node;
        if (new_node->value < temporary_node->value) {
            temporary_node = temporary_node->left_child;
        } else {
            temporary_node = temporary_node->right_child;
        }
    }

    new_node->parent = previous_to_temporary_node;
    if (previous_to_temporary_node == nullptr) {
        _root = new_node;
        _root->color = Color::black;
        return;
    } else if (previous_to_temporary_node->value > new_node->value) {
        previous_to_temporary_node->left_child = new_node;
    } else {
        previous_to_temporary_node->right_child = new_node;
    }

    if (new_node->parent->parent == nullptr) {
        return;
    }

    this->balance_tree(new_node);
}

void RedBlackTree::remove(int value) {
    Node *temporary_node = _root;

    while (temporary_node != nullptr) {
        if (temporary_node->value > value) {
            temporary_node = temporary_node->left_child;
        } else if (temporary_node->value < value) {
            temporary_node = temporary_node->right_child;
        } else {
            break;
        }
    }

    if (temporary_node == nullptr) {
        cout << "Value has not been found" << endl;
        return;
    }


}

