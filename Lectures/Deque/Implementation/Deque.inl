#include "Deque.h"
#include <iostream>

template <typename T>
Deque<T>::Deque() : mFront(0), mRear(0), mAddedElems(0) {}

template <typename T>
void Deque<T>::push_front(const T &element) {
    if (full()) {
        throw "Deque is full!";
    }
    mElements[mFront] = element;
    mAddedElems++;
    mFront++;
    mFront = mFront % MAX_SIZE;
}

template <typename T>
void Deque<T>::push_rear(const T &element) {
    if (full()) {
        throw "Deque is full!";
    }
    mElements[mRear] = element;
    mAddedElems++;
    mRear++;
    mRear = mRear % MAX_SIZE;
}