#include <stdlib.h>  // rand
#include "arrayList.h"

#define LIST_MAX_INDEX 10000000

ArrayLinkedList::ArrayLinkedList() {
    nodes_ = new ArrayNode[LIST_MAX_INDEX + 1];

    // Connect and loop list
    for (register int i = 0; i <= LIST_MAX_INDEX; i++) {
        nodes_[i].prev = &nodes_[i - 1];
        nodes_[i].next = &nodes_[i + 1];
    }
    nodes_[1].prev = &nodes_[LIST_MAX_INDEX];
    nodes_[LIST_MAX_INDEX].next = &nodes_[1];
    freeRoot_ = &nodes_[1];

    // Create root element
    root_ = &nodes_[0];
    root_->value = 0;
    root_->next = nullptr;
    root_->prev = nullptr;
}


ArrayLinkedList::~ArrayLinkedList() {
    delete[] nodes_;
}

ArrayNode* ArrayLinkedList::find(int valueToFind) {
    register ArrayNode *curNode = root_;
    while (curNode != nullptr && curNode->value != valueToFind)
        curNode = curNode->next;
    return curNode;
}

void ArrayLinkedList::insertAfter(ArrayNode *prevNode, int newValue) {
    register ArrayNode *newNode = freeRoot_;

    // Remove node from free nodes list
    freeRoot_ = freeRoot_->next;
    freeRoot_->prev = freeRoot_->prev->prev;
    freeRoot_->prev->next = freeRoot_;

    // Insert new node
    newNode->value = newValue;
    newNode->prev = prevNode;
    newNode->next = prevNode->next;

    if (prevNode->next != nullptr)
        newNode->next->prev = newNode;
    prevNode->next = newNode;
}

void ArrayLinkedList::remove(ArrayNode *nodeToRemove) {

    // Remove node
    if (nodeToRemove->prev != nullptr)
        nodeToRemove->prev->next = nodeToRemove->next;
    if (nodeToRemove->next != nullptr)
        nodeToRemove->next->prev = nodeToRemove->prev;

    // Add node to empty nodes list (after freeRoot_)
    nodeToRemove->next = freeRoot_->next;
    nodeToRemove->prev = freeRoot_;
    freeRoot_->next = nodeToRemove;
    nodeToRemove->next->prev = nodeToRemove;
}
