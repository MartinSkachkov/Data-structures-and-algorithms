#include "LStack.h"
#include <cassert>
#include <iostream>

template <typename T>
void LStack<T>::free() {
    while (!empty()) {
        pop();
    }
}

// copy stack by using temp stack
template <typename T>
void LStack<T>::copyStack(const LStack<T> &other) {
    mTopPtr = nullptr; // the top ptr will be changed when we push later

    StackElement<T> *p = other.mTopPtr;
    LStack<T> tmp; // we create an empty stack which will contain the flipped data

    while (p != nullptr) {
        tmp.push(p->data); // pushing the data from the other stack to the tmp stack
        p = p->next;       // slide the pointer to reach the next element
    }

    while (!tmp.empty()) {
        push(tmp.top()); // pushing elements and changing the top ptr
        tmp.pop();       // poping the last element so that we can reache the next one
    }
}

template <typename T>
LStack<T>::LStack() : mTopPtr(nullptr) {}

template <typename T>
LStack<T>::LStack(const LStack<T> &other) {
    copyStack(other);
}

template <typename T>
LStack<T>::LStack(LStack<T> &&other) {
    mTopPtr = other.mTopPtr; // steal the pointer
    other.mTopPtr = nullptr; // null out the stack ptr
}

template <typename T>
LStack<T> &LStack<T>::operator=(const LStack<T> &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copyStack(other);
    return *this;
}

template <typename T>
LStack<T> &LStack<T>::operator=(LStack<T> &&other) {
    if (this == &other) { // self assignment
        return *this;     // if they are the same object return the actual object
    }
    free();                  // deallocate the current storage
    mTopPtr = other.mTopPtr; // steal the pointer
    other.mTopPtr = nullptr; // null out the stack ptr
    return *this;
}

template <typename T>
LStack<T>::~LStack() {
    free();
}

template <typename T>
void LStack<T>::push(const T &data) {
    StackElement<T> *newElemPtr = new StackElement<T>; // allocate memory for a new StackElement
    newElemPtr->data = data;                           // save the data for the new element
    newElemPtr->next = mTopPtr;                        // create a link between the new element and the current top of the stack
    mTopPtr = newElemPtr;                              // change the top pointer to point to the new element as it is now the actual top
}

template <typename T>
T LStack<T>::pop() {
    if (empty()) {
        std::cerr << "Stack is empty and can't pop!";
        return T();
    }
    T result = top();
    StackElement<T> *tmpPtr = mTopPtr; // save the location of the top element
    mTopPtr = mTopPtr->next;           // change the top of the stack to point to the previous element
    delete tmpPtr;                     // delete the memory
    return result;
}

template <typename T>
T &LStack<T>::top() {
    assert(!empty());
    return mTopPtr->data;
}

template <typename T>
const T &LStack<T>::top() const {
    assert(!empty());
    return mTopPtr->data;
}

template <typename T>
bool LStack<T>::empty() const {
    return mTopPtr == nullptr;
}