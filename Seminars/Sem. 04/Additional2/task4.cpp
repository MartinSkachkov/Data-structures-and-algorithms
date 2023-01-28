#include "ll-utils.h"

template <typename T>
int size(const Node<T> *ll) {
    const Node<T> *it = ll;
    int c = 0;

    while (it != nullptr) {
        c++;
        it = it->next;
    }
    return c;
}

template <typename T>
Node<T> *sort(Node<T> *&ll) {
    if (ll == nullptr) {
        cerr << "Empty list!";
        throw "err!";
    }

    Node<T> *outer = ll;
    Node<T> *inner = ll->next;
    int listSize = size(ll);

    // bubble sort
    for (size_t i = 0; i < listSize - 1; i++) {
        for (size_t j = 0; j < listSize - 1 - i; j++) {
            if (outer->data > inner->data) {
                int tmp = outer->data;
                outer->data = inner->data;
                inner->data = tmp;
            }
            inner = inner->next;
        }
        outer = outer->next;
        inner = outer->next;
    }

    return ll;
}

int main() {
    Node<int> *ll = new Node<int>(4, new Node<int>(2, new Node<int>(1, new Node<int>(3, new Node<int>(8)))));
    Node<int> *ll2 = new Node<int>(-1, new Node<int>(5, new Node<int>(3, new Node<int>(4, new Node<int>(0)))));
    Node<int> *ll3 = new Node<int>(-1);
    Node<int> *n = nullptr;

    Node<int> *sorted = sort(ll);
    print(sorted);

    sorted = sort(ll2);
    print(sorted);

    sorted = sort(ll3);
    print(sorted);

    sorted = sort(n);
    print(sorted);

    free(ll);
    free(ll2);
    free(ll3);
    return 0;
}