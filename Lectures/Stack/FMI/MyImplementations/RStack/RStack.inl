#include "RStack.h"
#include <iostream>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare" // mutes the warning for the for loop ( i is unsigned and capacity is int)
// https://www.fluentcpp.com/2019/08/30/how-to-disable-a-warning-in-cpp/

template <typename T>
void RStack<T>::free() {
    delete[] mData;
}

template <typename T>
void RStack<T>::copyStack(const RStack<T> &other) {
    mTopIndex = other.mTopIndex;
    mCapacity = other.mCapacity;
    mData = new T[mCapacity];
    copyData(other.mData);
}

template <typename T>
void RStack<T>::copyData(const T *other) {
    for (unsigned int i = 0; i < mCapacity; i++) {
        mData[i] = other[i];
    }
}

template <typename T>
void RStack<T>::resize() {
    T *oldData = mData;           // save the location of the old data in the mem
    mData = new T[mCapacity * 2]; // allocate doubled mem and link the mData pointer to it
    copyData(oldData);            // copy the old data to the new memory
    mCapacity *= 2;               // double the capacity
    delete[] oldData;             // free the old memory
}

template <typename T>
RStack<T>::RStack() : mTopIndex(-1), mCapacity(DEFAULT_CAPACITY) {
    mData = new T[mCapacity];
}

template <typename T>
RStack<T>::RStack(const RStack<T> &other) {
    copyStack(other);
}

template <typename T>
RStack<T>::RStack(RStack<T> &&other) {
    mTopIndex = other.mTopIndex;
    mCapacity = other.mCapacity;
    mData = other.mData;   // steal the pointer
    other.mData = nullptr; // null out the stack ptr
}

template <typename T>
RStack<T> &RStack<T>::operator=(const RStack<T> &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copyStack(other);
    return *this;
}

template <typename T>
RStack<T> &RStack<T>::operator=(RStack<T> &&other) {
    if (this == &other) { // self assignment
        return *this;     // if they are the same object return the actual object
    }
    free();
    mTopIndex = other.mTopIndex;
    mCapacity = other.mCapacity;
    mData = other.mData;   // steal the pointer
    other.mData = nullptr; // null out the stack ptr
    return *this;
}

template <typename T>
RStack<T>::~RStack() {
    free();
}

template <typename T>
bool RStack<T>::empty() const {
    return mTopIndex == -1;
}

template <typename T>
bool RStack<T>::full() const {
    return mTopIndex == mCapacity - 1;
}

template <typename T>
void RStack<T>::push(const T &elem) {
    if (full()) {
        resize();
    }
    mData[++mTopIndex] = elem;
}

template <typename T>
T RStack<T>::pop() {
    if (empty()) {
        std::cerr << "Stack is empty and can't pop!\n";
        return T();
    }
    return mData[mTopIndex--];
}

template <typename T>
T RStack<T>::top() const {
    if (empty()) {
        std::cerr << "Stack is empty and can't top!\n";
        return T();
    }
    return mData[mTopIndex];
}

#pragma GCC diagnostic pop