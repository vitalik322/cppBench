//
// Pointer-based linked list
//

#ifndef POINTER_LIST_H
#define POINTER_LIST_H

struct PointerNode {
    int value = 0;
    PointerNode *next;
};

struct PointerLinkedList {
    PointerNode *root_ = new PointerNode();
    int size_ = 1;

    PointerNode *findPrev(int valueToFind);
    void insertAfter(PointerNode *prevNode, int newValue);
    void deleteAfter(PointerNode *prevNode);
};

void benchPointerList(int elementsNum);

#endif  // POINTER_LIST_H
