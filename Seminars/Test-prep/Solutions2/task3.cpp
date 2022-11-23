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
Node<T> *oddEvenList(Node<T> *ll) {
    if (ll == nullptr || ll->next == nullptr) {
        return ll;
    }

    Node<T> *evenStart = nullptr;
    Node<T> *evenEnd = nullptr;

    Node<T> *oddStart = nullptr;
    Node<T> *oddEnd = nullptr;

    bool oddPos = true;
    while (ll != nullptr) {
        if (!oddPos) {
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
        oddPos = !oddPos;
    }

    oddEnd->next = evenStart;
    evenEnd->next = nullptr;
    return oddStart;
}

int main() {
    Node<int> *ll1 = new Node<int>{1, new Node<int>{2, new Node<int>{3, new Node<int>{4, new Node<int>{5, nullptr}}}}};
    Node<int> *ll2 = new Node<int>{2, new Node<int>{1, new Node<int>{3, new Node<int>{5, new Node<int>{6, new Node<int>{4, new Node<int>{7, nullptr}}}}}}};
    Node<int> *res = oddEvenList(ll1);
    Node<int> *res2 = oddEvenList(ll2);
    print(res);
    free(res);
    print(res2);
    free(res2);
    return 0;
}