#ifndef _QUEUE_USING_2_STACKS_
#define _QUEUE_USING_2_STACKS_
#include <stack>

template <typename T>
class MyQueue {
private:
    std::stack<T> s1;
    std::stack<T> s2;

public:
    void push(const T &element);
    void pop();
    bool empty() const;
    T front() const;
};

template <typename T>
void MyQueue<T>::push(const T &element) {
    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
    s2.push(element);
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
}

template <typename T>
void MyQueue<T>::pop() {
    s2.pop();
}

template <typename T>
bool MyQueue<T>::empty() const {
    return s2.empty();
}

template <typename T>
T MyQueue<T>::front() const {
    return s2.top();
}

#endif