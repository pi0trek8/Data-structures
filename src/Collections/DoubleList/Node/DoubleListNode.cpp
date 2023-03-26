//
// Created by Piotr Szczypior on 25/03/2023.
//

#include "DoubleListNode.h"

DoubleListNode::DoubleListNode() {
    this->next_node = nullptr;
    this->previous_node = nullptr;
    this->value = 0;
}

DoubleListNode::DoubleListNode(int value) : value(value) {
    this->next_node = nullptr;
    this->previous_node = nullptr;
    this->value = value;
}

