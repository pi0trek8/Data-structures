//
// Created by Piotrek on 05/03/2023.
//

#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    this->head = nullptr;
}

void LinkedList::deleteNode(int index) {
    Node *temp = head, *temp2 = nullptr;
    int list_length = this->size();

//
//    while (temp->next_node != nullptr) {
//        temp = temp->next_node;
//        list_length++;
//    }

    if (index > list_length) {
        cout << "Index out of range" << endl;
        return;
    }

//    temp = head;

    if (index == 0) {
        head = head->next_node;
        delete temp;
        return;
    }

    for (int i = 0; i < index; i++) {
        temp2 = temp;
        temp = temp->next_node;
    }

    temp2->next_node = temp->next_node;

    delete temp;
}

void LinkedList::printList() {
    Node *temporary_node = head;

    if (head == nullptr) {
        cout << "list is empty" << endl;
        delete temporary_node;
        return;
    }

    cout << endl;
    while (temporary_node != nullptr) {
        cout << temporary_node->value << " ";
        temporary_node = temporary_node->next_node;
    }
}

void LinkedList::push_back(int value) {
    Node *new_node = new Node(value);

    if (head == nullptr) {
        head = new_node;
        return;
    }

    Node *temp = head;

    while (temp->next_node != nullptr) {
        temp = temp->next_node;
    }
    temp->next_node = new_node;
}

void LinkedList::push_front(int value) {
    Node *new_node = new Node(value);
    Node *temp1;

    temp1 = head;
    head = new_node;

    head->next_node = temp1;
}

void LinkedList::add(int value, int index) {
    Node *temp1, *temp2, *temp3;
    int list_size = this->size();
    Node *new_node = new Node(value);

    if (index == 0) {
        push_front(value);
        return;
    }

    if (index < 0 || index > list_size) {
        cout << "index: " << index << " is out of bounds of list with size: " << list_size << endl;
        return;
    }

    temp1 = head;

    for (int i = 0; i < index; i++) {
        temp2 = temp1;
        temp1 = temp1->next_node;
    }

    temp3 = temp1;
    temp1 = new_node;
    temp2->next_node = temp1;
    temp1->next_node = temp3;
}

int LinkedList::get(int index) {
    Node *temp = head;
    int list_size = this->size();

    if (index < 0 || index > list_size) {
        cout << "index: " << index << " is out of bounds of list with size: " << list_size << endl;
        return -1;
    }

    for (int i = 0; i < index; i++) {
        temp = temp->next_node;
    }

    return temp->value;
}

void LinkedList::pop_back() {
    Node *currentNode = head;
    Node *previousNode;

    if (currentNode->next_node == nullptr) {
        head = nullptr;
        delete head;
        return;
    }


    while (currentNode->next_node != nullptr) {
        previousNode = currentNode;
        currentNode = currentNode->next_node;
    }

    previousNode->next_node = nullptr;
    delete currentNode;
}

void LinkedList::pop_front() {
    Node *temporaryHeader = head;
    head = head->next_node;
    delete temporaryHeader;
}

LinkedList::~LinkedList() {
//    delete this;
}

int LinkedList::size() {
    Node *temporaryNode = head;
    int list_size = 0;

    while (temporaryNode != nullptr) {
        temporaryNode = temporaryNode->next_node;
        list_size++;
    }

    return list_size;
}

void LinkedList::swap(int source, int destination) {
//    Node *temporaryNode = nullptr;
//    Node *firstNode = head, *previous_first = head;
//    Node *secondNode = head, *previous_second = head;
//
//
//    int size = this->size();
//
//    for (int i = 0; i < source; i++) {
//        previous_first = firstNode;
//        firstNode = firstNode->next_node;
//    }
//    for (int i = 0; i < destination; i++) {
//        previous_second = secondNode;
//        secondNode = secondNode->next_node;
//    }
//
//    cout << endl << "First node " << secondNode->value << endl;
//    cout << "Second node " << firstNode->value << endl;
////    temporaryNode = firstNode;
////
////    firstNode->next_node = secondNode->next_node;
////    previous_second->next_node = firstNode;
////
////    secondNode->next_node = temporaryNode->next_node;
////    previous_first->next_node = secondNode;
//
//    std::swap(secondNode, firstNode);

    int i = source;

    int j = destination;

    if (i == j) {
        return;
    }

    // Find the nodes at the i-th and j-th positions
    Node* prev_i = nullptr;
    Node* node_i = head;
    for (int k = 0; k < i; k++) {
        prev_i = node_i;
        node_i = node_i->next_node;
    }

    Node* prev_j = nullptr;
    Node* node_j = head;
    for (int k = 0; k < j; k++) {
        prev_j = node_j;
        node_j = node_j->next_node;
    }

    // Swap the nodes
    if (prev_i) {
        prev_i->next_node = node_j;
    } else {
        head = node_j;
    }

    if (prev_j) {
        prev_j->next_node = node_i;
    } else {
        head = node_i;
    }

    Node* temp = node_i->next_node;
    node_i->next_node = node_j->next_node;
    node_j->next_node = temp;

}




