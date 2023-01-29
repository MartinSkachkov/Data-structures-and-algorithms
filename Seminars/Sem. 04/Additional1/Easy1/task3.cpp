#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node(const T &d, Node<T> *n = nullptr) : data(d), next(n) {}
};

template <typename T>
void deleteFront(Node<T> *&ll) {
    // empty list
    if (ll == nullptr) {
        cerr << "Empty list!";
        return;
    }

    // list with one or more elements
    Node<T> *toDel = ll;
    ll = ll->next;
    delete toDel;

    // when we deleted the only element in the list
    if (ll == nullptr) {
        cout << "Empty list!";
        return;
    }

    return;
}

template <typename T>
void print(const Node<T> *ll) {
    while (ll != nullptr) {
        cout << ll->data << ' ';
        ll = ll->next;
    }
}

template <typename T>
void destructor(Node<T> *ll) {
    while (ll) {
        Node<T> *toDel = ll;
        ll = ll->next;
        delete toDel;
    }
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    deleteFront(ll);
    deleteFront(ll);
    print(ll);

    free(ll);
    return 0;
}