#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node(const T &d, Node<T> *n = nullptr, Node<T> *p = nullptr) : data(d), next(n), prev(p) {}
};

template <typename T>
void print(Node<T> *ll) {
    while (ll != nullptr) {
        cout << ll->data << ' ';
        ll = ll->next;
    }
    cout << '\n';
}

template <typename T>
void free(Node<T> *ll) {
    while (ll != nullptr) {
        Node<T> *toDel = ll;
        ll = ll->next;
        delete toDel;
    }
}
