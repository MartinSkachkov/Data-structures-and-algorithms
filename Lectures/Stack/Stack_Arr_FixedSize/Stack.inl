#include "Stack.h"
#include <iostream>

template <typename T>
Stack<T>::Stack() : mCapacity(MAX_SIZE), mTop(-1) {}

template <typename T>
void Stack<T>::push(const T &elem) {
    if (full()) {
        std::cerr << "Stack is full!";
        return;
    } else {
        mS[++mTop] = elem;
    }
}

template <typename T>
T Stack<T>::pop() {
    if (empty()) {
        std::cerr << "Stack is empty!";
        return T();
    } else {
        return mS[mTop--];
    }
}

template <typename T>
T Stack<T>::top() const {
    if (empty()) {
        std::cerr << "Reached bottom of the stack!";
        return T();
    }
    return mS[mTop];
}

template <typename T>
bool Stack<T>::empty() const {
    return mTop == -1;
}

template <typename T>
bool Stack<T>::full() const {
    return mTop == mCapacity - 1;
}

template <typename T>
int Stack<T>::capacty() const {
    return mCapacity;
}