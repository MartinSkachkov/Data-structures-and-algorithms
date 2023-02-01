#include "../Easy1/ll-utils.h"

template <typename T>
int extractNum(Node<T> *ll) {
    int num = 0;

    while (ll != nullptr) {
        num = num * 10 + ll->data;
        ll = ll->next;
    }

    int rev = 0;

    while (num != 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }

    return rev;
}

template <typename T>
int addLists(Node<T> *ll1, Node<T> *ll2) {
    if (ll1 == nullptr && ll2 == nullptr) {
        return INT_MIN;
    }

    if (ll1 == nullptr) {
        return extractNum(ll2);
    }

    if (ll2 == nullptr) {
        return extractNum(ll1);
    }

    int x = extractNum(ll1);
    int y = extractNum(ll2);

    return x + y;
}

int main() {
    Node<int> *ll1 = new Node<int>(1, new Node<int>(2, new Node<int>(3)));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(3)));

    cout << addLists(ll1, ll2);

    free(ll1);
    return 0;
}