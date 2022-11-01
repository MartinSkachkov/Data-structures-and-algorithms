#include "LL_utils.h"
#include <iostream>

// we create a new node and link the data with the passed data and next with the front of the ll, then change the front to point to the new Node
template <typename T>
void insertAtBeg(LLNode<T> *&ll, const T &data) {
    LLNode<T> *newNode = new LLNode<T>(data, ll);
    ll = newNode;
}

int main() {
    LLNode<int> *ll = new LLNode<int>(1, new LLNode<int>(2, new LLNode<int>(3)));
    printLL(ll);
    insertAtBeg(ll, 0);
    printLL(ll);
    free(ll);

    return 0;
}