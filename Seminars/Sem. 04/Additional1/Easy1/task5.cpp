#include "ll-utils.h"

template <typename T>
bool sameLists(const Node<T> *l1, const Node<T> *l2) {
    // contents check
    while (l1 && l2) {
        if (l1->data != l2->data) {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    // length check
    if (l1 == nullptr && l2 == nullptr) {
        return true;
    }
    return false;
}

int main() {
    Node<int> *l1 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    Node<int> *l2 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    Node<int> *l3 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(6)))));
    Node<int> *l4 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, new Node<int>(8))))));

    cout << sameLists(l1, l2); // same
    cout << sameLists(l2, l3); // contents
    cout << sameLists(l3, l4); // length

    free(l1);
    free(l2);
    free(l3);
    free(l4);
    return 0;
}