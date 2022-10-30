#include "LQueue.h"
#include <iostream>

template <typename T>
void LQueue<T>::copyQueue(const LQueue<T> &other) {
    QueueElement<T> *iter = other.mHead;
    while (iter) {
        push(iter->data);
        iter->next;
    }
}

template <typename T>
void LQueue<T>::free() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
LQueue<T>::LQueue() : mHead(nullptr), mTail(nullptr), mSize(0) {}

template <typename T>
LQueue<T>::LQueue(const LQueue<T> &other) {
    copy(other);
}

template <typename T>
LQueue<T>::LQueue(LQueue<T> &&other) {
    mSize = other.mSize;
    mHead = other.mHead;
    mTail = other.mTail;
    other.mHead = nullptr;
    other.mTail = nullptr;
}

template <typename T>
LQueue<T> &LQueue<T>::operator=(const LQueue<T> &other) {
    if (this == &other) {
        return *this;
    }
    free();
    copy(other);
    return *this;
}

template <typename T>
LQueue<T> &LQueue<T>::operator=(LQueue<T> &&other) {
    if (this == &other) {
        return *this;
    }
    free();
    mSize = other.mSize;
    mHead = other.mHead;
    mTail = other.mTail;
    other.mHead = nullptr;
    other.mTail = nullptr;
    return *this;
}

template <typename T>
LQueue<T>::~LQueue() {
    free();
}

template <typename T>
void LQueue<T>::push(const T &element) {
    QueueElement<T> *newElem = new QueueElement<T>;
    newElem->mData = element;
    newElem->mNext = nullptr;
    mTail->mNext = newElem;
    mTail = newElem;
    mSize++;
}

template <typename T>
void LQueue<T>::pop() {
    if (empty()) {
        throw std::runtime_error("You can not delete the top element of an empty stack!");
    }
    QueueElement<T> *tmp = mHead;
    mHead = mHead->mNext;
    delete tmp;
    mSize--;
}

template <typename T>
bool LQueue<T>::empty() const {
    return mHead == nullptr;
}

template <typename T>
const T &LQueue<T>::front() const {
    if (empty()) {
        throw std::runtime_error("You can not get the top element of an empty stack!");
    }
    return mHead->mData;
}

template <typename T>
T &LQueue<T>::front() {
    if (empty()) {
        throw std::runtime_error("You can not get the top element of an empty stack!");
    }
    return mHead->mData;
}

template <typename T>
unsigned LQueue<T>::size() const {
    return mSize;
}