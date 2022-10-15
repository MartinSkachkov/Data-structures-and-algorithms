#include "Stack.h"
#include <iostream>

template <typename T>
void Stack<T>::copyStack(const T *other) { // ptr to const (int) or other type a.k.a we cannot change the values
    for (size_t i = 0; i < mSize; i++) {
        mS[i] = other[i];
    }
}

template <typename T>
void Stack<T>::copy(const Stack<T> &other) {
    mTop = other.mTop;
    mSize = other.mSize;
    mS = new T[mSize];
    copyStack(other);
}

template <typename T>
void Stack<T>::resize() {
    T *oldStack = mS;      // copy the pointer to the memory
    mS = new T[2 * mSize]; // newly allocated mem and we link the mS ptr with it
    copyStack(oldStack);   // copy the values
    mSize *= 2;            // resized
    delete[] oldStack;     // deleting the old memory
}

template <typename T>
void Stack<T>::free() {
    delete[] mS;
}

template <typename T>
Stack<T>::Stack(int size) {
    mSize = size;
    mTop = -1;
    mS = new T[size];
}

template <typename T>
Stack<T>::Stack(const Stack<T> &other) {
    copy(other);
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other) {
    if (this == &other) {
        return this;
    }
    free();
    copy(other);
    return *this;
}

template <typename T>
Stack<T>::~Stack() {
    free();
}

template <typename T>
void Stack<T>::push(const T &elem) {
    if (full()) {
        // std::cout << "Stack is full and can't push!";
        // return;
        resize();
        mS[++mTop] = elem;
    } else {
        mS[++mTop] = elem;
    }
}

template <typename T>
T Stack<T>::pop() {
    if (empty()) {
        std::cerr << "Removing an element from empty stack!\n";
        return T(); //?
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
bool Stack<T>::full() const {
    return mTop == mSize - 1;
}

template <typename T>
bool Stack<T>::empty() const {
    return mTop == -1;
}

template <typename T>
int Stack<T>::size() const {
    return mSize;
}