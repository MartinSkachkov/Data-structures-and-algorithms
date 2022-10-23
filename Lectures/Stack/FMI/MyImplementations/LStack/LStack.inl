#include "LStack.h"
#include <iostream>

template <typename T>
void LStack<T>::free() {
    while (!empty()) {
        pop();
    }
}

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