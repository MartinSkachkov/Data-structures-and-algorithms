#include <iostream>

template <typename T>
struct LLNode {
    T mData;
    LLNode<T> *mNext;

    LLNode(const T &data, LLNode<T> *ptr = nullptr) : mData(data), mNext(ptr) {}
};

template <typename T>
void printLL(const LLNode<T> *ll) { // ll is a pointer to the front
    const LLNode<T> *iterator = ll; // create a copy to the front pointer

    while (iterator) {
        std::cout << iterator->mData << ' ';
        iterator = iterator->mNext;
    }
    std::cout << '\n';
}

template <typename T>
void free(LLNode<T> *ll) {
    LLNode<T> *tmpPtr = nullptr;
    while (ll) {
        tmpPtr = ll;
        ll = ll->mNext;
        delete tmpPtr;
    }
}