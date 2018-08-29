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
    nodes_[0].prev = &nodes_[LIST_MAX_INDEX];
    nodes_[LIST_MAX_INDEX].next = &nodes_[0];
    freeRoot_ = &nodes_[1];

    // Create root element
    root_ = &nodes_[0];
    root_->value = 0;
}


ArrayLinkedList::~ArrayLinkedList() {
    delete nodes_;
}

ArrayNode* ArrayLinkedList::find(int valueToFind) {
    register ArrayNode *curNode = root_;
    while (curNode->value != valueToFind && curNode->next != nullptr)
        curNode = curNode->next;
    return curNode;
}

void ArrayLinkedList::insertAfter(ArrayNode *prevNode, int newValue) {
    register ArrayNode *newNode = freeRoot_;

    // Remove node from free nodes list
    freeRoot_->prev->next = freeRoot_->next;
    freeRoot_->next->prev = freeRoot_->prev;
    freeRoot_ = freeRoot_->next;

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
    nodeToRemove->prev->next = nodeToRemove->next;
    nodeToRemove->next->prev = nodeToRemove->prev;

    // Add node to empty nodes list (after freeRoot_)
    nodeToRemove->next = freeRoot_->next;
    nodeToRemove->prev = freeRoot_;
    freeRoot_->next = nodeToRemove;
    nodeToRemove->next->prev = nodeToRemove;
}

void benchArrayListFind(int elementsNum) {
    ArrayLinkedList list;
    register ArrayNode *node;

    for (register int i = 0; i < elementsNum; ++i) {
        node = list.find(i);
        list.insertAfter(node, i + 1);
    }

    for (register int i = elementsNum - 1; i > 0; --i) {
        node = list.find(i);
        list.remove(node);
    }
}

void benchArrayList(int elementsNum) {
    ArrayLinkedList list;

    for (register int j = 0; j < elementsNum; ++j) {
        register ArrayNode *node = list.root_;
        for (register int i = 0; i < elementsNum; ++i) {
            list.insertAfter(node, i + 1);
            node = node->next;
        }

        node = list.root_;
        register ArrayNode *nextNode = node->next;
        for (register int i = 0; i < elementsNum; ++i) {
            nextNode = node->next;
            list.remove(node);
            node = nextNode;
        }
    }
}

