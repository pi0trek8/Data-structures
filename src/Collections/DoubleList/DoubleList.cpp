//
// Created by Piotr Szczpior on 09.03.2023.
//

#include <iostream>
#include "DoubleList.h"
#include "Node/DoubleListNode.h"

using namespace std;


void DoubleList::push_back(int element) {
    // checking if head has been initialized
    if (head == nullptr) {
        head = new DoubleListNode(element);
        tail = head;
        list_size++;
        return;
    }

    DoubleListNode *temporary_node = tail;
    tail = new DoubleListNode(element);
    temporary_node->next_node = tail;
    tail->previous_node = temporary_node;
    list_size++;
}

void DoubleList::push_front(int element) {
    if (head == nullptr) {
        head = new DoubleListNode(element);
        tail = head;
        list_size++;
        return;
    }

    auto *temporary = head;
    head = new DoubleListNode(element);
    head->next_node = temporary;
    temporary->previous_node = head;
    list_size++;
}

void DoubleList::insert(int element, int index) {
    // check if index is not out of bounds
    if (index < 0 || index > list_size) {
        cerr << "index: " << index << " is out of bounds for length: " << list_size << endl;
        return;
    }
    // initialize new node
    auto *new_node = new DoubleListNode(element);

    // first case index == 0
    if (index == 0) {
        auto temporary_node = head;
        head = new_node;
        new_node->next_node = temporary_node;
        temporary_node->previous_node = new_node;
        list_size++;
        return;
    }

    // second case new node as last element
    if (index == list_size) {
        auto temporary_node = tail;
        tail = new_node;
        temporary_node->next_node = tail;
        tail->previous_node = temporary_node;
        list_size++;
        return;
    }

    DoubleListNode *temporary_node;

    // check if index is in first or second half
    // and based on that starting iterating from first or last node
    if (index < list_size / 2) {
        temporary_node = head;
        for (int i = 0; i < index - 1; i++) {
            temporary_node = temporary_node->next_node;
        }
    } else {
        temporary_node = tail;
        for (int i = 0; i < index - 1; i++) {
            temporary_node = temporary_node->previous_node;
        }
    }

    auto *node_to_slide = temporary_node->next_node;
    // creating hierarchy with new node
    temporary_node->next_node = new_node;
    new_node->previous_node = temporary_node;
    if (node_to_slide != nullptr) {
        // sliding node and keeping hierarchy
        new_node->next_node = node_to_slide;
        node_to_slide->previous_node = new_node;
    }
    list_size++;
}

void DoubleList::remove(int index) {
    // check if index is not out of bounds
    if (index < 0 || index >= list_size) {
        cerr << "index: " << index << " is out of bounds for length: " << list_size << endl;
        return;
    }
    // first case
    if (index == 0) {
        pop_front();
        return;
    }
    // second case
    if (index == list_size - 1) {
        pop_back();
        return;
    }

    // default case:

    DoubleListNode *temporary_node;

    // check if index is in first or second half
    // and based on that starting iterating from first or last node
    if (index < list_size / 2) {
        temporary_node = head;
        for (int i = 0; i < index - 1; i++) {
            temporary_node = temporary_node->next_node;
        }
    } else {
        temporary_node = tail;
        for (int i = 0; i < index - 1; i++) {
            temporary_node = temporary_node->previous_node;
        }
    }

    auto *node_to_slide = temporary_node->next_node->next_node;

    delete temporary_node->next_node;

    // creating hierarchy with new node
    if (node_to_slide == nullptr) {
        // sliding node and keeping hierarchy
        temporary_node->next_node = nullptr;
        return;
    }
    temporary_node->next_node = node_to_slide;
    node_to_slide->previous_node = temporary_node;
    list_size--;
}

void DoubleList::pop_front() {
    if (list_size == 0) {
        cout << "list is empty" << endl;
        return;
    }
    // first and only element
    if (list_size == 1) {
        auto temp_node = head;
        tail = nullptr;
        head = nullptr;
        delete temp_node;
        list_size--;
        return;
    }
    // default element
    auto *temporary_head = head;
    head->next_node->previous_node = nullptr;
    head = head->next_node;
    delete temporary_head;
    list_size--;
}

void DoubleList::pop_back() {
    if (list_size == 0) {
        cout << "list is empty" << endl;
        return;
    }
    //last and only element
    if (list_size == 1) {
        auto temp_node = head;
        head = nullptr;
        tail = nullptr;
        delete temp_node;
        list_size--;
        return;
    }
    //default case
    DoubleListNode *temporary_node = tail;

    temporary_node->previous_node->next_node = nullptr;
    tail = tail->previous_node;
    delete temporary_node;
    list_size--;
}

void DoubleList::clear() {
    // iterating throughout list and removing node objects one by one
    auto *temporary_node = head;
    DoubleListNode *node_to_delete;
    for (int i = 0; i < list_size; i++) {
        node_to_delete = temporary_node;
        temporary_node = temporary_node->next_node;
        delete node_to_delete;
    }
    // deleting last node
    delete temporary_node;

    // reinitializing pointers
    head = nullptr;
    tail = nullptr;
    list_size = 0;
}

bool DoubleList::find(int element) {
    // searching through structure to meet search criteria
    DoubleListNode *temporary_node = head;
    while (temporary_node != nullptr) {
        if (temporary_node->value == element) {
            return true;
        }
        temporary_node = temporary_node->next_node;
    }
    return false;
}

void DoubleList::print() {
    DoubleListNode *temporary_node = head;

    if (head == nullptr) {
        cout << "list is empty" << endl;
        delete temporary_node;
        return;
    }

    while (temporary_node != nullptr) {
        cout << temporary_node->value << " ";
        temporary_node = temporary_node->next_node;
    }
    cout << endl;
}

void DoubleList::swap(int first_index, int second_index) {

    if (first_index < 0 || first_index >= list_size || second_index >= list_size || second_index < 0) {
        cout << "Index out of bounds exception" << endl;
        return;
    }

    if (first_index == second_index) {
        return;
    }

    // Find the nodes at the first_index-th and last_index-th positions
    DoubleListNode *previous_node_first_index = nullptr;
    DoubleListNode *node_first_index = head;
    for (int i = 0; i < first_index; i++) {
        previous_node_first_index = node_first_index;
        node_first_index = node_first_index->next_node;
    }

    DoubleListNode *previous_node_second_index = nullptr;
    DoubleListNode *node_second_index = head;
    for (int i = 0; i < second_index; i++) {
        previous_node_second_index = node_second_index;
        node_second_index = node_second_index->next_node;
    }

    // Swap the nodes
    if (previous_node_first_index != nullptr) {
        previous_node_first_index->next_node = node_second_index;
        node_second_index->previous_node = previous_node_first_index;
    } else {
        head = node_second_index;
    }

    if (previous_node_second_index != nullptr) {
        previous_node_second_index->next_node = node_first_index;
        node_first_index->previous_node = previous_node_second_index;
    } else {
        head = node_first_index;
    }

    DoubleListNode *temp = node_first_index->next_node;
    node_first_index->next_node = node_second_index->next_node;
    if (node_second_index->next_node != nullptr) {
        node_second_index->next_node->previous_node = node_first_index;
    }

    node_second_index->next_node = temp;
    if (temp != nullptr) {
        temp->previous_node = node_second_index;
    }
}

int DoubleList::get(int index) {
    if (index < 0 || index >= list_size) {
        throw invalid_argument("index: " + to_string(index) + " is out of bounds for length: " + to_string(list_size));
    }
    DoubleListNode *temporary_node;

    // iterating based on index value: from beginning, from end
    if (index < list_size / 2) {
        temporary_node = head;
        for (int i = 0; i < index; i++) {
            temporary_node = temporary_node->next_node;
        }
    } else {
        temporary_node = tail;
        for (int i = 0; i < index; i++) {
            temporary_node = temporary_node->previous_node;
        }
    }

    return temporary_node->value;
}

int DoubleList::get_size() {
    return list_size;
}

string DoubleList::get_name() {
    // utils method in order to distinguish structure object without reflection in C++
    return "List";
}

DoubleList::DoubleList() {
    // initializing pointers with default values
    this->list_size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}


