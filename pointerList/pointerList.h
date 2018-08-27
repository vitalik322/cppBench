//
// Pointer-based linked list
//

#ifndef POINTER_LIST_H
#define POINTER_LIST_H

struct PointerNode {
    int value = 0;
    PointerNode *prev;
    PointerNode *next;
};

struct PointerLinkedList {
    PointerNode *root_ = new PointerNode();
    int size_ = 1;

    PointerNode *find(int valueToFind);
    void insertAfter(PointerNode *prevNode, int newValue);
    void remove(PointerNode *node);
};

void benchPointerList(int elementsNum);
void benchPointerListFind(int elementsNum);

#endif  // POINTER_LIST_H
