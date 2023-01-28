#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node(const T &d, Node<T> *n = nullptr) : data(d), next(n) {}
};

template <typename T>
void freeList(Node<T> *ll) {
    while (ll != nullptr) {
        Node<T> *toDel = ll;
        ll = ll->next;
        delete toDel;
    }
}

template <typename T>
Node<T> *&reverseList(Node<T> *&head) {
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;

    while (head != nullptr) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;

    return head;
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    Node<int> *it = ll;

    cout << "before:\n";
    while (it != nullptr) {
        cout << it->data << ' ';
        it = it->next;
    }
    it = ll;
    cout << '\n';

    cout << "after:\n";
    it = reverseList(ll);
    while (it != nullptr) {
        cout << it->data << ' ';
        it = it->next;
    }
    it = ll;

    return 0;
}