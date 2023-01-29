#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node(const T &d, Node<T> *n = nullptr) : data(d), next(n) {}
};

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

    free(ll);
    return 0;
}