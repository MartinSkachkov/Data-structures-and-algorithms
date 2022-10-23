#include "StaticStack.h"
#include <iostream>

template <typename T>
StaticStack<T>::StaticStack() : mTopIndx(-1) {}

template <typename T>
bool StaticStack<T>::empty() const {
    return mTopIndx == -1;
}

template <typename T>
bool StaticStack<T>::full() const {
    return mTopIndx == MAX_CAPACITY - 1;
}

template <typename T>
void StaticStack<T>::push(const T &elem) {
    if (full()) {
        std::cerr << "Stack is full and can't push!\n";
        return;
    }
    mData[++mTopIndx] = elem;
}

template <typename T>
T StaticStack<T>::pop() {
    if (empty()) {
        std::cerr << "Stack is empty and can't pop!\n";
        return T();
    }
    return mData[mTopIndx--];
}

template <typename T>
T StaticStack<T>::top() const {
    if (empty()) {
        std::cerr << "Stack is empty and can't take the last element!\n";
        return T();
    }
    return mData[mTopIndx];
}