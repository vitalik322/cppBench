#define STACK_SIZE 100000000

//
// Array-based stack
//

struct StackArray {
    int *arr_ = new int[STACK_SIZE];
    long long topIndex_ = 0;

    int pop() { return arr_[topIndex_--]; }
    void push(int elem) { arr_[++topIndex_] = elem; }
    ~StackArray() { delete arr_; }
};

//
// List-based stack
//

struct StackNode {
    StackNode(int v) { value = v; }
    int value;
    StackNode* prev;
};

struct StackList {
    StackNode *sp_;
    int pop();
    void push(int value);
};

void benchStackList(int opNum);
void benchStackArray(int opNum);
