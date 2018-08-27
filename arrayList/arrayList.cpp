#include <stdlib.h>  // rand
#include "arrayList.h"

#define LIST_MAX_INDEX 100000

ArrayLinkedList::ArrayLinkedList() {
    nodes_ = new ArrayNode[LIST_MAX_INDEX + 1];

    // Loop list
    for (int i = 0; i <= LIST_MAX_INDEX; i++) {
        nodes_[i].prev = i - 1;
        nodes_[i].next = i + 1;
    }
    nodes_[0].prev = LIST_MAX_INDEX;
    nodes_[LIST_MAX_INDEX].next = 0;
    freeRoot_ = 1;

    // Create root element
    root_ = 0;
    size_ = 1;
    nodes_[root_].value = 0;
    nodes_[root_].next = -1;
    nodes_[root_].prev = -1;
}

int ArrayLinkedList::find(int valueToFind) {
    register int curNode = root_;
    while (nodes_[curNode].value != valueToFind && curNode != -1)
        curNode = nodes_[curNode].next;
    return curNode;
}   

void ArrayLinkedList::insertAfter(int prevNode, int newValue) {
    // Get new node index
    int newNode = freeRoot_;

    // Remove node from free nodes list
    nodes_[nodes_[freeRoot_].prev].next = nodes_[freeRoot_].next;
    nodes_[nodes_[freeRoot_].next].prev = nodes_[freeRoot_].prev;
    freeRoot_ = nodes_[freeRoot_].next;
    
    // Insert new node
    nodes_[newNode].value = newValue;
    nodes_[newNode].next = nodes_[prevNode].next;
    nodes_[newNode].prev = prevNode;
    nodes_[prevNode].next = newNode;
    nodes_[nodes_[newNode].next].prev = newNode;

    ++size_;
}

void ArrayLinkedList::remove(int nodeToRemove) {

    // Remove node
    nodes_[nodes_[nodeToRemove].prev].next = nodes_[nodeToRemove].next;
    nodes_[nodes_[nodeToRemove].next].prev = nodes_[nodeToRemove].prev;

    // Add node to empty nodes list (after freeRoot_)
    nodes_[nodeToRemove].next = nodes_[freeRoot_].next;
    nodes_[nodeToRemove].prev = freeRoot_;
    nodes_[freeRoot_].next = nodeToRemove;
    nodes_[nodes_[nodeToRemove].next].prev = nodeToRemove;

    --size_;
}

void benchArrayListFind(int elementsNum) {
    ArrayLinkedList list;

    int node;
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

    int node = 0;
    for (register int i = 0; i < elementsNum; ++i) {
        list.insertAfter(node, i + 1); 
        node = list.nodes_[node].next;
    }   

    node = 0;
    int nextNode = list.nodes_[node].next;
    for (register int i = 0; i < elementsNum; ++i) {
        nextNode = list.nodes_[node].next;
        list.remove(node);
        node = nextNode;
    }   
}

