#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node(const T &d, Node<T> *n = nullptr) : data(d), next(n) {}
};

template <typename T>
void free(Node<T> *ll) {
    while (ll != nullptr) {
        Node<T> *toDel = ll;
        ll = ll->next;
        delete toDel;
    }
}

template <typename T>
void print(const Node<T> *ll) {
    while (ll != nullptr) {
        cout << ll->data << ' ';
        ll = ll->next;
    }
    cout << '\n';
}