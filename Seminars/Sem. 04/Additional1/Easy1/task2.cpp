#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node(const T &d, Node<T> *n = nullptr) : data(d), next(n) {}
};

template <typename T>
void insertFront(Node<T> *&ll, T data) {
    // empty list
    if (ll == nullptr) {
        ll = new Node<T>(data);
        return;
    }

    // list with one or more elements
    Node<T> *newElem = new Node<T>(data);
    newElem->next = ll;
    ll = newElem;

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
    insertFront(ll, 16);
    insertFront(ll, 20);
    print(ll);

    free(ll);
    return 0;
}