#ifndef _STACK_USING_QUEUE_H_
#define _STACK_USING_QUEUE_H_
#include <queue>

template <typename T>
class MyStack {
private:
    std::queue<T> q;
    unsigned mNumOfElems;

public:
    MyStack();

    void push(const T &element);
    void pop();
    bool empty() const;
    T top() const;
};

template <typename T>
MyStack<T>::MyStack() : mNumOfElems(0) {}

template <typename T>
void MyStack<T>::push(const T &element) {
    mNumOfElems++;
    T x;

    // Idea: move all the elements before the current pushed element behind it so that it becomes the first
    q.push(element);
    for (size_t i = 0; i < mNumOfElems - 1; i++) {
        x = q.front();
        q.pop();
        q.push(x);
    }
}

template <typename T>
void MyStack<T>::pop() {
    q.pop();
}

template <typename T>
bool MyStack<T>::empty() const {
    return q.empty();
}

template <typename T>
T MyStack<T>::top() const {
    return q.front();
}

#endif