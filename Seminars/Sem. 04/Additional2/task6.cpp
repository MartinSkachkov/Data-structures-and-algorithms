#include "ll-utils.h"

template <typename T>
void deleteNode(Node<T> *&ll, int x) {
    Node<T> *prev = nullptr;
    Node<T> *it = ll;

    if (it == nullptr) { // empty list
        cerr << "Empty list!";
        return;
    } else if (it->data == x) { // delete head
        Node<T> *toDel = it;
        it = it->next;
        delete toDel;

        if (it == nullptr) {
            ll = it;
            cerr << "Empty list!";
            return;
        }

        ll = it;
        return;
    }

    while (it != nullptr) {
        if (it->data == x) {
            Node<T> *toDel = it;
            it = it->next;
            delete toDel;
            prev->next = it;
            return;
        }

        prev = it;
        it = it->next;
    }

    cerr << "Element doesn't exist!\n";
    return;
}

int main() {
    Node<int> *ll = new Node<int>(4, new Node<int>(4, new Node<int>(5, new Node<int>(1, new Node<int>(9)))));
    Node<int> *ll2 = new Node<int>(4);

    deleteNode(ll, 1);
    print(ll);

    deleteNode(ll, 9);
    deleteNode(ll, 4);
    print(ll);

    deleteNode(ll, 1);
    deleteNode(ll2, 4);

    if (ll)
        free(ll);
    if (ll2)
        free(ll2);
    return 0;
}