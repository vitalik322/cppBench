#define STACK_SIZE 1000000

struct Stack {
    int *arr_ = new int[STACK_SIZE];
    int topIndex_ = 0;

    int pop() { return arr_[topIndex_--]; }
    void push(int elem) { arr_[++topIndex_] = elem; }
    ~Stack() { delete arr_; }
};

int fibRec(int num) {
    if (num == 1 || num == 2)
        return 1;
    return fibRec(num - 1) + fibRec(num - 2);
}

Stack stack;
int fibStack(int num) {
    int prev1, prev2;
    while (num != 0) {
        if (num == 1 || num == 2) {
            stack.push(1);
            continue;
        }

        prev1 = stack.pop();
        prev2 = stack.pop();
        stack.push(num - 1);
        stack.push(num - 2);
        num--;
    }
}
