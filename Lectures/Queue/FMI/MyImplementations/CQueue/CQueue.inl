#include "CQueue.h"
#include <cassert>
#include <iostream>

template <typename T>
int CQueue<T>::nextIndx(int pos) const {
    return (pos + 1) % MAX_CAP;
}

template <typename T>
CQueue<T>::CQueue() : mFront(0), mBack(0), mAddedElems(0) {}

template <typename T>
void CQueue<T>::push(const T &elem) {
    assert(!full());
    mElements[mBack] = elem; // insert the element
    mBack = nextIndx(mBack); // move the back
    mAddedElems++;
}

template <typename T>
T CQueue<T>::pop() {
    assert(!empty());
    T elem = mElements[mFront]; // get the element
    mFront = nextIndx(mFront);  // move the front
    mAddedElems--;
    return elem;
}

template <typename T>
T CQueue<T>::front() const {
    assert(!empty());
    return mElements[mFront];
}

template <typename T>
bool CQueue<T>::empty() const {
    return mAddedElems == 0;
}

template <typename T>
bool CQueue<T>::full() const {
    return mAddedElems == MAX_CAP;
}

template <typename T>
int CQueue<T>::size() const {
    return mAddedElems;
}