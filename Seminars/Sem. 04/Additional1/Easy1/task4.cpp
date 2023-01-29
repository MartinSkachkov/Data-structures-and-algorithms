#include "ll-utils.h"

template <typename T>
void printNthFromEnd(Node<T> *&ll, int n) {
    Node<T> *dummyHead = new Node<T>(T(), ll);
    Node<T> *slow = dummyHead, *fast = dummyHead;

    for (size_t i = 0; i < n + 1; i++) {
        fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    cout << slow->next->data;
    return;
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    print(ll);

    printNthFromEnd(ll, 2);
    printNthFromEnd(ll, 1);
    printNthFromEnd(ll, 3);

    free(ll);
    return 0;
}