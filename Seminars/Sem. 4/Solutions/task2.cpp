#include "LL_utils.h"
#include <iostream>

// we only redirect the pointers
template <typename T>
void reverseLL(LLNode<T> *&ll) {
    LLNode<T> *previous = nullptr;
    LLNode<T> *next = nullptr;
    LLNode<T> *iterate = ll;

    while (iterate) {
        next = iterate->mNext;
        iterate->mNext = previous;
        previous = iterate;
        iterate = next;
    }
    ll = previous;
}

int main() {
    LLNode<int> *ll = new LLNode<int>(1, new LLNode<int>(2, new LLNode<int>(3)));
    printLL(ll);
    reverseLL(ll);
    printLL(ll);
    free(ll);
    return 0;
}