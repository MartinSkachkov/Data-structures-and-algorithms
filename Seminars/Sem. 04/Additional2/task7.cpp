#include "ll-utils.h"

template <typename T>
void removeNthFromEnd(Node<T> *&ll, int n) {
    Node<T> *dummyHead = new Node<T>(T(), ll);
    Node<T> *slow = dummyHead, *fast = dummyHead;

    for (size_t i = 0; i < n + 1; i++) {
        fast = fast->next;
    }

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    Node<T> *toDel = slow->next;
    slow->next = slow->next->next;
    delete toDel;
    ll = dummyHead->next;
    return;
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    removeNthFromEnd(ll, 2);
    removeNthFromEnd(ll, 1);
    removeNthFromEnd(ll, 3);
    print(ll);

    free(ll);
    return 0;
}