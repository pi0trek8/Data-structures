//
// Created by pszczypi on 09.03.2023.
//

#include "DoubleList.h"


void DoubleList::push_front(int value) {
    if(head == nullptr) {
        head = new Node(value);
        return;
    }


}

void DoubleList::deleteValue(int value) {
    Node* foundNode = find(value);
    if(foundNode == nullptr) {
        return;
    }

    if(foundNode == head) {
        head = head->next;
        head->previous = nullptr;
        delete foundNode;
        return;
    }

    (foundNode->previous)->next = foundNode->next;
    delete foundNode;
}
