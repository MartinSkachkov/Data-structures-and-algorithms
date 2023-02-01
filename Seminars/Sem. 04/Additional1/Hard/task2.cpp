#include "../Easy1/ll-utils.h"

template <typename T>
void insertAlternate(Node<T> *ll1, Node<T> *ll2) {
    if (ll1 == nullptr && ll2 == nullptr) {
        cout << "Both lists are empty!";
        return;
    }

    if (ll1 == nullptr) {
        ll1 = ll2;
        return;
    }

    if (ll2 == nullptr) {
        ll2 = ll1;
        return;
    }

    // both have at least one element
    Node<T> *it1 = ll1, *it2 = ll2;

    while (it1 != nullptr && it2 != nullptr) {
        Node<T> *nextEl1 = it1->next;
        Node<T> *nextEl2 = it2->next;

        // do an alternation
        it1->next = it2;
        if (nextEl1 == nullptr)
            break;
        it2->next = nextEl1;

        // move to the next element
        it1 = nextEl1;
        it2 = nextEl2;
    }
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3)));
    Node<int> *ll1 = new Node<int>(4, new Node<int>(5, new Node<int>(6)));
    Node<int> *single = new Node<int>(4);
    Node<int> *empty = nullptr;
    Node<int> *ll2 = new Node<int>(4, new Node<int>(5, new Node<int>(6, new Node<int>(7, new Node<int>(8, new Node<int>(9, new Node<int>(10)))))));
    Node<int> *ll3 = new Node<int>(11, new Node<int>(32, new Node<int>(55, new Node<int>(4, new Node<int>(50, new Node<int>(17, new Node<int>(7)))))));

    // insertAlternate(ll, ll1);
    // print(ll);

    // insertAlternate(ll, single);
    // print(ll);

    // insertAlternate(ll,ll2);
    // print(ll);

    insertAlternate(empty, ll3);
    print(ll3);

    // free(ll);
    // free(ll1);
    // free(ll2);
    free(ll3);
    // free(single);
    return 0;
}