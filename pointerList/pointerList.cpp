#include <stdlib.h>  // rand
#include "pointerList.h"

PointerNode *PointerLinkedList::findPrev(int valueToFind) {
    if (root_ == nullptr) {
        return nullptr;
    }

    PointerNode *curNode = root_;
    while (curNode->value != valueToFind)
        if (curNode->next == nullptr)
            return nullptr;
        else
            curNode = curNode->next;

    return curNode;
}   

void PointerLinkedList::insertAfter(PointerNode *prevNode, int newValue) {
    PointerNode *newNode = new PointerNode();
    newNode->value = newValue;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    ++size_;
}

void PointerLinkedList::deleteAfter(PointerNode *prevNode) {
    if (prevNode->next == nullptr)
        return;

    PointerNode *nodeToDelete = prevNode->next;
    prevNode->next = nodeToDelete->next;
    delete nodeToDelete;

    --size_;
}

void benchPointerList(int elementsNum) {
    PointerLinkedList list;
    PointerNode *node;
    for (register int i = 0; i < elementsNum; ++i) {
        node = list.findPrev(i);
        list.insertAfter(node, i + 1);
    }
    for (register int i = elementsNum - 1; i > 0; --i) {
        node = list.findPrev(i);
        list.deleteAfter(node);
    }
}
