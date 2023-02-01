#include "../Easy1/ll-utils.h"

template <typename T>
Node<T> *reverseKElems(Node<T> *&head, int k) {
    if (head == nullptr) {
        return head;
    }

    Node<T> *curr = head;
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
    int count = 0;

    // reverse first k nodes of the linked list
    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != nullptr) {
        head->next = reverseKElems(next, k);
    }

    return prev;
}

int main() {
    Node<int> *ll1 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, new Node<int>(6))))));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(3)));

    Node<int> *res = reverseKElems(ll1, 3);
    print(res);

    free(ll1);
    free(ll2);
    return 0;
}