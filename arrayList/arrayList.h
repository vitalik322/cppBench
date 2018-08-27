//
// Array-based linked list
//

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

struct ArrayNode {
    int value = 0;
    int prev = -1;
    int next = -1;
};

struct ArrayLinkedList {

    ArrayLinkedList();
    ~ArrayLinkedList();

    ArrayNode *nodes_;
    int root_ = 0;
    int freeRoot_ = 0;

    int find(int valueToFind);
    void insertAfter(int prevNode, int newValue);
    void remove(int node);
};

void benchArrayList(int elementsNum);
void benchArrayListFind(int elementsNum);

#endif  // ARRAY_LIST_H
