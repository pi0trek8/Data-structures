//
// Created by Piotrek on 05/03/2023.
//

#include "Node.h"

Node::Node() {
    this->next_node = nullptr;
    this->value = 0;
}

Node::Node(int value) : value(value) {
    this->next_node = nullptr;
    this->value = value;
}
