#include "pointerList.h"

PointerNode *PointerLinkedList::find(int valueToFind) {
    register PointerNode *curNode = root_;
    while (curNode != nullptr && curNode->value != valueToFind)
        curNode = curNode->next;
    return curNode;
}   

void PointerLinkedList::insertAfter(PointerNode *prevNode, int newValue) {
    register PointerNode *newNode = new PointerNode();
    newNode->value = newValue;
    newNode->prev = prevNode;
    newNode->next = prevNode->next;

    if (prevNode->next != nullptr)
        prevNode->next->prev = newNode;
    prevNode->next = newNode;
}

void PointerLinkedList::remove(PointerNode *nodeToRemove) {
    if (nodeToRemove->prev != nullptr)
        nodeToRemove->prev->next = nodeToRemove->next;
    if (nodeToRemove->next != nullptr)
        nodeToRemove->next->prev = nodeToRemove->prev;
    delete nodeToRemove;
}

PointerLinkedList::~PointerLinkedList() {
    PointerNode *node = root_;
    while (root_ != nullptr) {
        node = root_->next;
        delete root_;
        root_ = node;
    }
}
