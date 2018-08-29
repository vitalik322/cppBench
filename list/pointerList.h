//
// Pointer-based linked list
//

#ifndef POINTER_LIST_H
#define POINTER_LIST_H

struct PointerNode {
    int value = 0;
    PointerNode *prev = nullptr;
    PointerNode *next = nullptr;
};

struct PointerLinkedList {
    PointerNode *root_ = new PointerNode();

    PointerNode *find(int valueToFind);
    void insertAfter(PointerNode *prevNode, int newValue);
    void remove(PointerNode *node);
    ~PointerLinkedList();
};

#endif  // POINTER_LIST_H
