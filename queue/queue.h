#define QUEUE_SIZE 100000000

//
// Array-based queue
//

struct QueueArray {
    int *arr_ = new int[QUEUE_SIZE];
    long long topIndex_ = 0;
    long long botIndex_ = 0;

    int pop();
    void push(int elem);
    ~QueueArray() { delete[] arr_; }
};
