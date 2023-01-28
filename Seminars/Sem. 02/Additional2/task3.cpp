#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    int *arr;
    int size;
    int topIndx;
    int minEl;

    void resize();
    void copyStack(const MinStack &other);
    void copyArr(const int *other);
    void free();

public:
    MinStack();
    MinStack(const MinStack &other);
    MinStack(MinStack &&other);
    MinStack &operator=(const MinStack &other);
    MinStack &operator=(MinStack &&other);
    ~MinStack();

    void push(const int &val);
    void pop();
    int top() const;
    int getMin();
};

void MinStack::resize() {
    int *old = arr;
    arr = new int[size * 2];
    copyArr(old);
    size *= 2;
    delete[] old;
}

void MinStack::copyStack(const MinStack &other) {
    size = other.size;
    topIndx = other.topIndx;
    minEl = other.minEl;

    arr = new int[size];
    copyArr(other.arr);
}

void MinStack::copyArr(const int *other) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = other[i];
    }
}

void MinStack::free() {
    delete[] arr;
}

MinStack::MinStack() : topIndx(-1), size(8), minEl(INT_MAX) {
    arr = new int[size];
}

MinStack::MinStack(const MinStack &other) {
    copyStack(other);
}

MinStack::MinStack(MinStack &&other) {
    size = other.size;
    topIndx = other.topIndx;
    minEl = other.minEl;
    arr = other.arr;
    other.arr = nullptr;
}

MinStack &MinStack::operator=(const MinStack &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copyStack(other);
    return *this;
}

MinStack &MinStack::operator=(MinStack &&other) {
    if (this == &other) {
        return *this;
    }
    free();
    size = other.size;
    topIndx = other.topIndx;
    minEl = other.minEl;
    arr = other.arr;
    other.arr = nullptr;

    return *this;
}

MinStack::~MinStack() {
    free();
}

void MinStack::push(const int &val) {
    if (topIndx == size - 1) {
        throw "Full Stack!";
    }
    arr[++topIndx] = val;
}

void MinStack::pop() {
    if (topIndx == -1) {
        throw "Empty Stack!";
    }
    topIndx--;
}

int MinStack::top() const {
    return arr[topIndx];
}

int MinStack::getMin() {
    for (int i = 0; i < size; i++) {
        if (minEl > arr[i]) {
            minEl = arr[i];
        }
    }
    return minEl;
}

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin(); // return -3
    minStack.pop();
    cout << minStack.top();    // return 0
    cout << minStack.getMin(); // return -2

    return 0;
}