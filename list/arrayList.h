//
// Array-based linked list
//

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

struct ArrayNode {
    int value = 0;
    ArrayNode *prev = nullptr;
    ArrayNode *next = nullptr;
};

struct ArrayLinkedList {

    ArrayLinkedList();
    ~ArrayLinkedList();

    ArrayNode *nodes_;
    ArrayNode *root_ = nullptr;
    ArrayNode *freeRoot_ = nullptr;

    ArrayNode* find(int valueToFind);
    void insertAfter(ArrayNode* prevNode, int newValue);
    void remove(ArrayNode* node);
};

#endif  // ARRAY_LIST_H
