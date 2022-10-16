#include "StrangeStack.h"
#include <iostream>

template <typename T>
void StrangeStack<T>::free() {
    delete[] stack;
}

template <typename T>
void StrangeStack<T>::copy(const StrangeStack<T> &other) {
    capacity = other.capacity;
    size = other.size;
    top = other.top;
    copyStack(other.stack);
}

template <typename T>
void StrangeStack<T>::copyStack(const T *stack) {
    for (size_t i = capacity - 1; i >= 0; i++) {
        this->stack[i] = stack[i];
        top = i;
    }
}

template <typename T>
void StrangeStack<T>::resize() {
    T *oldStack = stack;
    stack = new T[capacity * 2];
    capacity *= 2;
    copyStack(oldStack);
    delete[] oldStack;
}

template <typename T>
bool StrangeStack<T>::full() const {
    return top == 0;
}

template <typename T>
bool StrangeStack<T>::empty() const {
    return top == capacity;
}

template <typename T>
StrangeStack<T>::StrangeStack(int capacity) : size(0), top(capacity) {
    this->capacity = capacity;
    stack = new T[capacity];
}

template <typename T>
StrangeStack<T>::StrangeStack(const StrangeStack<T> &other) {
    copy(other);
}

template <typename T>
StrangeStack<T> &StrangeStack<T>::operator=(const StrangeStack<T> &other) {
    if (this == other) {
        return *this;
    }
    free();
    copy(other);
    return *this;
}

template <typename T>
StrangeStack<T>::~StrangeStack() {
    free();
}

template <typename T>
int StrangeStack<T>::addedElements() const {
    return size;
}

template <typename T>
bool StrangeStack<T>::push(const T &elem) {
    if (full()) {
        std::cerr << "Stack is full! Resizing... Push again";
        resize();
        return false;
    }
    stack[--top] = elem;
    size++;
    return true;
}

template <typename T>
bool StrangeStack<T>::pop() {
    if (empty()) {
        std::cerr << "Stack is empty!";
        return false;
    }
    top++;
    size--;
    return true;
}

template <typename T>
bool StrangeStack<T>::peek() const {
    if (empty()) {
        return false;
    }
    return true;
}

template <typename T>
int StrangeStack<T>::getTop() const {
    return top;
}