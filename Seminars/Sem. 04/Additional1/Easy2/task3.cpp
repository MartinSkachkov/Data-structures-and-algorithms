#include "../Easy1/ll-utils.h"

template <typename T>
void reverseList(Node<T> *&ll) {
    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;

    while (ll != nullptr) {
        next = ll->next;
        ll->next = prev;
        prev = ll;
        ll = next;
    }
    ll = prev;
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    reverseList(ll);
    print(ll);

    free(ll);
    return 0;
}