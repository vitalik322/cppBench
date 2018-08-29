#include <cassert>
#include <iostream>

#include "listBench.h"
#include "arrayList.h"
#include "pointerList.h"

void testLists() {
    std::cout << "testing lists" << std::endl;
    ArrayLinkedList arrayList;
    PointerLinkedList pointerList;
    for (register int i = 0; i < 1000; ++i) {
        int randNum = rand() % 1000 + 1;
    
        if (pointerList.find(randNum) == nullptr)
            assert(arrayList.find(randNum) == nullptr);
        else
            assert(pointerList.find(randNum)->value == arrayList.find(randNum)->value);

        if (arrayList.find(randNum) != nullptr) {  // if num exists - insert new one, or remove
            if (rand() % 2) {  // insert
                int newValue = rand() % 1000 + 1;
                arrayList.insertAfter(arrayList.find(randNum), newValue);
                pointerList.insertAfter(pointerList.find(randNum), newValue);
            }
            else {  // remove
                arrayList.remove(arrayList.find(randNum));
                pointerList.remove(pointerList.find(randNum));
            }
        }
        else {  // if num doesn't exist - insert new one
            arrayList.insertAfter(arrayList.root_, randNum);
            pointerList.insertAfter(pointerList.root_, randNum);
        }
    }
    std::cout << "ok" << std::endl;
}

void benchPointerListFind(int elementsNum) {
    PointerLinkedList list;
    register PointerNode *node;

    for (register int i = 0; i < elementsNum; ++i) {
        node = list.find(i);
        list.insertAfter(node, i + 1); 
    }   

    for (register int i = elementsNum - 1; i > 0; --i) {
        node = list.find(i);
        list.remove(node);
    }   
}

void benchPointerListInsertRemove(int elementsNum) {
    PointerLinkedList list;

    for (register int j = 0; j < elementsNum; ++j) {
        register PointerNode *node = list.root_;
        for (register int i = 0; i < elementsNum; ++i) {
            list.insertAfter(node, i + 1); 
            node = node->next;
        }

        for (register int i = 0; i < elementsNum; ++i)
            list.remove(list.root_->next);
    }   
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

void benchArrayListInsertRemove(int elementsNum) {
    ArrayLinkedList list;

    for (register int j = 0; j < elementsNum; ++j) {
        register ArrayNode *node = list.root_;
        for (register int i = 0; i < elementsNum; ++i) {
            list.insertAfter(node, i + 1); 
            node = node->next;
        }   

        for (register int i = 0; i < elementsNum; ++i)
            list.remove(list.root_->next);
    }   
}
