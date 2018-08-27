#include <stdlib.h>  // rand
#include "pointerList.h"

PointerNode *PointerLinkedList::find(int valueToFind) {
    PointerNode *curNode = root_;
    while (curNode->value != valueToFind && curNode->next != nullptr)
        curNode = curNode->next;

    return curNode;
}   

void PointerLinkedList::insertAfter(PointerNode *prevNode, int newValue) {
    PointerNode *newNode = new PointerNode();
    newNode->value = newValue;
    newNode->prev = prevNode;
    newNode->next = prevNode->next;

    if (prevNode->next != nullptr)
        prevNode->next->prev = newNode;
    prevNode->next = newNode;
    ++size_;
}

void PointerLinkedList::remove(PointerNode *node) {
    if (node->next == nullptr)
        return;

    PointerNode *nodeToDelete = node->next;
    node->next = nodeToDelete->next;
    delete nodeToDelete;

    --size_;
}

void benchPointerListFind(int elementsNum) {
    PointerLinkedList list;
    PointerNode *node;

    for (register int i = 0; i < elementsNum; ++i) {
        node = list.find(i);
        list.insertAfter(node, i + 1);
    }

    for (register int i = elementsNum - 1; i > 0; --i) {
        node = list.find(i);
        list.remove(node);
    }
}

void benchPointerList(int elementsNum) {
    PointerLinkedList list;

    for (register int j = 0; j < elementsNum; ++j) {
        PointerNode *node = list.find(0);
        for (register int i = 0; i < elementsNum; ++i) {
            list.insertAfter(node, i + 1);
            node = node->next;
        }

        node = list.find(0);
        PointerNode *nextNode = node->next;
        for (register int i = 0; i < elementsNum; ++i) {
            nextNode = node->next;
            list.remove(node);
            node = nextNode;
        }
    }
}
