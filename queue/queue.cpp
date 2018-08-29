#include "queue.h"

//
// Array-based queue
//

void QueueArray::push(int elem) {
    if (topIndex_ < QUEUE_SIZE - 1)
        ++topIndex_;
    else
        topIndex_ = 0;
    arr_[topIndex_] = elem;
}

int QueueArray::pop() {
    register int res = arr_[botIndex_];
    if (botIndex_ < QUEUE_SIZE - 1)
        ++botIndex_;
    else
        botIndex_ = 0;
    return res;
}
