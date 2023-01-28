#include "LL_utils.h"
#include <iostream>

template <typename T>
const T &findMiddle(const LLNode<T> *ll) {
    const LLNode<T> *slowPtr = ll;
    const LLNode<T> *fastPtr = ll;

    while (fastPtr && fastPtr->mNext) {
        slowPtr = slowPtr->mNext;
        fastPtr = fastPtr->mNext->mNext;
    }
    return slowPtr->mData;
}

int main() {
    LLNode<int> *ll = new LLNode<int>(1, new LLNode<int>(2, new LLNode<int>(3, new LLNode<int>(4, new LLNode<int>(5)))));
    printLL(ll);
    std::cout << findMiddle(ll);
    free(ll);
    return 0;
}