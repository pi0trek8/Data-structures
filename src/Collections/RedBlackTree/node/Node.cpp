#include "Node.h"

//
// Created by Piotr Szczypior on 03/04/2023.
//
Node::Node(int value) : value(value) {
    this->value = value;
    this->left_child = nullptr;
    this->right_child = nullptr;
    this->parent = nullptr;
    this->color = Color::red;
}
