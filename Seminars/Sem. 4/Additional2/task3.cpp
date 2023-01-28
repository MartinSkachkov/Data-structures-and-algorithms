#include "ll-utils.h"

template <typename T>
Node<T> *mergeSorted(Node<T> *ll1, Node<T> *ll2) {
    Node<T> *dummyHead = new Node<T>(T());
    Node<T> *dummy = dummyHead;

    while (ll1 || ll2) {
        if (ll1 == nullptr) {
            dummy->next = ll2;
            ll2 = ll2->next;
            continue;
        }

        if (ll2 == nullptr) {
            dummy->next = ll1;
            ll1 = ll1->next;
            continue;
        }

        if (ll1->data > ll2->data) {
            dummy->next = ll2;
            ll2 = ll2->next;
        } else {
            dummy->next = ll1;
            ll1 = ll1->next;
        }
        dummy = dummy->next;
    }

    return dummyHead->next;
}

int main() {
    Node<int> *ll1 = new Node<int>(1, new Node<int>(2, new Node<int>(3)));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(3, new Node<int>(4)));

    Node<int> *merged = mergeSorted(ll1, ll2);

    print(merged);
    free(merged);
    return 0;
}