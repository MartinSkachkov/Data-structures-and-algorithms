#include "ll-utils.h"

int reverseNum(int x) {
    int rev = 0;

    while (x) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev;
}

template <typename T>
int llToNum(const Node<T> *ll) {
    int num = 0;

    while (ll != nullptr) {
        num *= 10;
        num += ll->data;
        ll = ll->next;
    }

    return reverseNum(num);
}

template <typename T>
Node<T> *convertToList(T num) {
    Node<T> *newList = new Node<int>(num % 10);
    Node<T> *start = newList;
    num /= 10;

    while (num != 0) {
        newList->next = new Node<int>(num % 10);
        num /= 10;
        newList = newList->next;
    }

    return start;
}

int main() {
    Node<int> *ll1 = new Node<int>(2, new Node<int>(4, new Node<int>(3)));
    Node<int> *ll2 = new Node<int>(5, new Node<int>(6, new Node<int>(4)));

    int x = llToNum(ll1);
    int y = llToNum(ll2);

    Node<int> *res = convertToList(x + y);
    print(res);
    free(res);

    Node<int> *ll3 = new Node<int>(0);
    Node<int> *ll4 = new Node<int>(0);

    x = llToNum(ll3);
    y = llToNum(ll4);

    res = convertToList(x + y);
    print(res);

    free(ll1);
    free(ll2);
    free(ll3);
    free(ll4);
    free(res);
    return 0;
}