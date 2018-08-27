#include "stack.h"

//
// List-based stack
//

int StackList::pop() {
    StackNode *topNode = sp_;
    sp_ = sp_->prev;
    int res = topNode->value;
    delete topNode;
    return res;
}

void StackList::push(int value) {
    StackNode *newNode = new StackNode(value);
    newNode->prev = sp_;
    sp_ = newNode;
}

//
// Bench functions
//

void benchStackList(int opNum) {
    StackList stack;
    for (register int i1 = 0; i1 < opNum; ++i1)
        for (register int i2 = 0; i2 < opNum; ++i2)
            stack.push(i2);
    for (register int i1 = 0; i1 < opNum; ++i1)
        for (register int i2 = 0; i2 < opNum; ++i2)
            stack.pop();
}

void benchStackArray(int opNum) {
    StackArray stack;
    for (register int i1 = 0; i1 < opNum; ++i1)
        for (register int i2 = 0; i2 < opNum; ++i2)
            stack.push(i2);
    for (register int i1 = 0; i1 < opNum; ++i1)
        for (register int i2 = 0; i2 < opNum; ++i2)
            stack.pop();
}
