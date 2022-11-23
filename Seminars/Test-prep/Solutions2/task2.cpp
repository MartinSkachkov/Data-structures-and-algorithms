#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
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
Node<T> *rearange(Node<T> *ll) {
    Node<T> *evenStart = nullptr;
    Node<T> *evenEnd = nullptr;

    Node<T> *oddStart = nullptr;
    Node<T> *oddEnd = nullptr;

    while (ll != nullptr) {
        if (ll->data % 2 == 0) {
            if (evenStart == nullptr) {
                evenStart = evenEnd = ll;
            } else {
                evenEnd->next = ll;
                evenEnd = evenEnd->next;
            }
        } else {
            if (oddStart == nullptr) {
                oddStart = oddEnd = ll;
            } else {
                oddEnd->next = ll;
                oddEnd = oddEnd->next;
            }
        }
        ll = ll->next;
    }

    if (evenStart == nullptr && oddStart != nullptr) {
        return oddStart;
    }
    evenEnd->next = oddStart;
    oddEnd->next = nullptr;
    return evenStart;
}

int main() {
    Node<int> *ll1 = new Node<int>{3, new Node<int>{5, new Node<int>{2, new Node<int>{9, new Node<int>{4, nullptr}}}}};
    Node<int> *ll2 = new Node<int>{1, new Node<int>{2, nullptr}};
    Node<int> *res = rearange(ll1);
    Node<int> *res2 = rearange(ll2);
    print(res);
    free(res);
    print(res2);
    free(res2);
    return 0;
}