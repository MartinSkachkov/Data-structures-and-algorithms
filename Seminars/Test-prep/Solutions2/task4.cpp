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
Node<T> *reverseKGroup(Node<T> *ll, int k) {
    Node<T> *prev = nullptr;
    Node<T> *next = nullptr;
    Node<T> *iter = ll;
    unsigned c = k;

    Node<T> *checkLength = ll;
    while (checkLength && c) {
        checkLength = checkLength->next;
        c--;
    }
    if (c != 0) {
        return ll;
    }

    c = k;
    while (ll && c > 0) {
        next = iter->next;
        iter->next = prev;
        prev = iter;
        iter = next;
        c--;
    }

    if (iter != nullptr) {
        ll->next = reverseKGroup(iter, k);
    }
    return prev;
}

int main() {
    Node<int> *ll1 = new Node<int>{1, new Node<int>{2, new Node<int>{3, new Node<int>{4, new Node<int>{5, nullptr}}}}};
    Node<int> *ll2 = new Node<int>{1, new Node<int>{2, new Node<int>{3, new Node<int>{4, new Node<int>{5, nullptr}}}}};
    Node<int> *ll3 = new Node<int>{1, nullptr};
    Node<int> *newLL1 = reverseKGroup(ll1, 3);
    Node<int> *newLL2 = reverseKGroup(ll2, 2);
    Node<int> *newLL3 = reverseKGroup(ll3, 1);
    print(newLL1);
    print(newLL2);
    print(newLL3);
    free(ll1);
    free(ll2);
    free(ll3);
    return 0;
}