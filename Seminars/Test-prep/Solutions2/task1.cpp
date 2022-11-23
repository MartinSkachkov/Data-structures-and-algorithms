#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node(const T &d, Node<T> *n) : data(d), next(n) {}
};

template <typename T>
void print(const Node<T> *ll) {
    while (ll) {
        cout << ll->data << ' ';
        ll = ll->next;
    }
    cout << '\n';
}

template <typename T>
void free(Node<T> *ll) {
    while (ll) {
        Node<T> *toDelete = ll;
        ll = ll->next;
        delete toDelete;
    }
}

template <typename T>
Node<T> *mergeSort(Node<T> *ll1, Node<T> *ll2) {
    if (ll1 == nullptr) {
        return ll2;
    }
    if (ll2 == nullptr) {
        return ll1;
    }

    Node<T> *newStart = nullptr;
    Node<T> *newEnd = nullptr;

    while (ll1 != nullptr && ll2 != nullptr) {
        if (ll1 && ll2 && ll1->data <= ll2->data) {
            if (newStart == nullptr) {
                newStart = newEnd = ll1;
            } else {
                newEnd->next = ll1;
                newEnd = newEnd->next;
            }
            ll1 = ll1->next;
        }

        if (ll1 && ll2 && ll2->data <= ll1->data) {
            if (newStart == nullptr) {
                newStart = newEnd = ll2;
            } else {
                newEnd->next = ll2;
                newEnd = newEnd->next;
            }
            ll2 = ll2->next;
        }
    }

    Node<T> *rest = (ll1 == nullptr) ? ll2 : ll1;
    while (rest != nullptr) {
        newEnd->next = rest;
        newEnd = newEnd->next;
        rest = rest->next;
    }

    newEnd->next = nullptr;
    return newStart;
}

int main() {
    Node<int> *ll1 = new Node<int>(1, new Node<int>(2, new Node<int>(4, new Node<int>(8, new Node<int>(16, nullptr)))));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(5, new Node<int>(7, new Node<int>(9, new Node<int>(16, nullptr)))))));
    Node<int> *res = mergeSort(ll1, ll2);
    print(res);
    free(res);
    return 0;
}