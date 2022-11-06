#include "SLL.h"

template <typename T>
LinkedListIterator<T>::LinkedListIterator(LLE *pos) : mPtr(pos) {}

template <typename T>
typename LinkedListIterator<T>::I LinkedListIterator<T>::next() const {
    if (!valid()) {
        return *this; // ако сме стигнали края на списъка втъщаме текущият итератор
    }
    return I(mPtr->mNext); // Създава нов обект итератор, който се свързва със следващия елемент на списъка
}

template <typename T>
bool LinkedListIterator<T>::valid() const {
    return mPtr != nullptr;
}

template <typename T>
const T &LinkedListIterator<T>::getData() const {
    return mPtr->mData;
}

template <typename T>
T &LinkedListIterator<T>::getData() {
    return mPtr->mData;
}

template <typename T>
LinkedListIterator<T>::operator bool() const {
    return valid();
}

template <typename T>
typename LinkedListIterator<T>::I &LinkedListIterator<T>::operator++() {
    return (*this = next());
}
template <typename T>
typename LinkedListIterator<T>::I LinkedListIterator<T>::operator++(int) {
    I copy = *this;
    *this = next();
    return copy;
}

template <typename T>
T &LinkedListIterator<T>::operator*() {
    return getData();
}

template <typename T>
bool LinkedListIterator<T>::operator==(const I &other) const {
    return mPtr == other.mPtr;
}

template <typename T>
bool LinkedListIterator<T>::operator!=(const I &other) const {
    return mPtr != other.mPtr;
}

template <typename T>
typename LinkedListIterator<T>::I &LinkedListIterator<T>::operator+=(unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        (*this)++;
    }
    return *this;
}

//////////////////////////////////////////////////////////

template <typename T>
void LinkedList<T>::free() {
    while (!empty()) {
        deleteFirst();
    }
}

template <typename T>
LinkedList<T>::LinkedList() : mHead(nullptr), mTail(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other) : mHead(nullptr), mTail(nullptr) {
    append(other);
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&other) : mHead(other.mHead), mTail(other.mTail) {
    other.mHead = nullptr;
    other.mTail = nullptr;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other) {
    if (this == &other) {
        return *this;
    }
    free();
    append(other);
    return *this;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&other) {
    if (this == &other) {
        return *this;
    }
    free();
    mHead = other.mHead;
    mTail = other.mTail;
    other.mHead = nullptr;
    other.mTail = nullptr;
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    free();
}

template <typename T>
typename LinkedList<T>::I LinkedList<T>::begin() const {
    return I(mHead); // създава итератор и го връша по копие
}

template <typename T>
typename LinkedList<T>::I LinkedList<T>::end() const {
    return I(); // създава итератор и го връша по копие
}

template <typename T>
bool LinkedList<T>::empty() const {
    return mHead == nullptr && mTail == nullptr;
}

template <typename T>
const T &LinkedList<T>::getAt(const I &it) const {
    return it.getData();
}

template <typename T>
T &LinkedList<T>::getAt(const I &it) {
    return it.getData();
}

template <typename T>
bool LinkedList<T>::insertBefore(const I &it, const T &x) {
    if (it == begin()) {
        LLE *newElem = new LLE{x, mHead};
        mHead = newElem;
        if (mTail == nullptr) {
            mTail = newElem;
        }
        return true;
    }
    return insertAfter(findPrev(it), x);
}

template <typename T>
bool LinkedList<T>::insertAfter(const I &it, const T &x) {
    if (empty()) {
        return inserFirst(x);
    }

    LLE *newElem = new LLE{x, nullptr};
    if (!it || it.mPtr == mTail) {
        mTail->mNext = newElem;
        mTail = newElem;
    } else {
        newElem->mNext = it.mPtr->mNext;
        it.mPtr->mNext = newElem;
    }
    return true;
}

template <typename T>
bool LinkedList<T>::insertFirst(const T &x) {
    return insertBefore(begin(), x);
}

template <typename T>
bool LinkedList<T>::insertLast(const T &x) {
    return insertAfter(end(), x);
}

/*
template <typename T>
    template <typename T>
    template <typename T>
    template <typename T>
    */
