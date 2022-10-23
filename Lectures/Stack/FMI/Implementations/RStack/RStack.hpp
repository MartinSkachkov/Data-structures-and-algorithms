#ifndef _RESIZABLE_STACK_HPP
#define _RESIZABLE_STACK_HPP

#include <cassert>
#include <iostream>

template <typename T>
class RStack {
private:
    T *arr;
    int topIndex;
    int capacity;

    bool full() const;
    void resize();
    void copy(T const *);
    void eraseStack();
    void copyStack(RStack const &);

public:
    RStack();
    RStack(RStack const &);
    RStack(RStack &&); // move constructor
    RStack &operator=(RStack const &);
    RStack &operator=(RStack &&); // move operator=
    ~RStack();

    bool empty() const;
    void push(T const &x);
    T pop();
    T top() const;
};

const unsigned INITIAL_CAPACITY = 16;

template <typename T>
RStack<T>::RStack() : topIndex(-1), capacity(INITIAL_CAPACITY) {
    arr = new T[capacity];
}

template <typename T>
bool RStack<T>::empty() const {
    return topIndex == -1;
}

template <typename T>
bool RStack<T>::full() const {
    return topIndex == capacity - 1;
}

template <typename T>
T RStack<T>::pop() {
    if (empty()) {
        std::cerr << "Stack is empty!\n";
        return T();
    }
    return arr[topIndex--];
}

template <typename T>
T RStack<T>::top() const {
    if (empty()) {
        std::cerr << "Stack is empty!\n";
        return T();
    }
    return arr[topIndex];
}

template <typename T>
void RStack<T>::eraseStack() {
    delete[] arr;
}

template <typename T>
RStack<T>::~RStack() {
    eraseStack();
}

template <typename T>
void RStack<T>::push(T const &x) {
    if (full()) {
        resize();
    }
    arr[++topIndex] = x;
}

template <typename T>
void RStack<T>::copy(T const *stackArr) {
    for (unsigned i = 0; i < capacity; i++) {
        arr[i] = stackArr[i];
    }
}

template <typename T>
void RStack<T>::copyStack(RStack const &stack) {
    topIndex = stack.topIndex;
    capacity = stack.capacity;
    arr = new T[capacity];
    copy(stack.arr);
}

template <typename T>
void RStack<T>::resize() {
    T *oldStackPtr = arr;
    arr = new T[2 * capacity];
    copy(oldStackPtr);
    capacity *= 2;
    delete[] oldStackPtr;
}

template <typename T>
RStack<T>::RStack(RStack<T> const &stack) {
    copyStack(stack);
}

// move constructor
template <typename T>
RStack<T>::RStack(RStack<T> &&stack) {
    arr = stack.arr;     // steal the pointer
    stack.arr = nullptr; // null out the stack ptr
    topIndex = stack.topIndex;
    capacity = stack.capacity;
    std::cout << "Move constructor\n";
}

template <typename T>
RStack<T> &RStack<T>::operator=(RStack<T> const &stack) {
    if (this != &stack) {
        eraseStack();
        copyStack(stack);
    }
    return *this;
}

// move op=
template <typename T>
RStack<T> &RStack<T>::operator=(RStack<T> &&stack) {
    if (this == &stack) { // self assignment
        return *this;     // if they are the same object return the actual object
    }
    eraseStack();        // deallocate the current storage
    arr = stack.arr;     // steal the pointer
    stack.arr = nullptr; // null out the stack ptr
    topIndex = stack.topIndex;
    capacity = stack.capacity;
    std::cout << "Move operator=\n";
    return *this; // return the current object
}

#endif