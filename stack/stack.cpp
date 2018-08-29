#include "stack.h"

//
// List-based stack
//

int StackList::pop() {
    register StackNode *topNode = sp_;
    sp_ = sp_->prev;
    register int res = topNode->value;
    delete topNode;
    return res;
}

void StackList::push(int value) {
    register StackNode *newNode = new StackNode(value);
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

int _calcFacRec(int n, int res = 1) {
    if (n == 1)
        return res;
    return _calcFacRec(n - 1, res * n);
}

void benchFacRec(int n, int iters) {
    for (int i = 0; i < iters; ++i)
        _calcFacRec(n);
}

// TODO
int _calcFacStack(int n) {
    StackArray stack;
    for (register int i = n; i > 0; --i)
        stack.push(i);
    for (register int i = 0; i < n; ++i)
        stack.push(stack.pop() * stack.pop());
    return stack.pop();
}

void benchFacStack(int n, int iters) {
    for (int i = 0; i < iters; ++i)
        _calcFacStack(n);

}
