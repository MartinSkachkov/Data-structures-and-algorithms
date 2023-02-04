#include "C:\Users\Marto\Desktop\Data-structures-and-algorithms\Seminars\Sem. 04\Additional2\ll-utils.h"

template <typename T>
bool checkIfPal(Node<T> *&start, Node<T> *&end) {
    if (end == nullptr) {
        return true;
    }

    bool res = checkIfPal(start, end->next) && (start->data == end->data);
    start = start->next;
    return res;
}

template <typename T>
bool isPal(Node<T> *head) {
    if (head == nullptr) {
        return true;
    }

    Node<T> *start = head;
    Node<T> *end = head;
    return checkIfPal(start, end);
}

int main() {
    Node<int> *ll1 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, new Node<int>(6))))));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(1)));

    cout << isPal(ll1);
    cout << isPal(ll2);

    free(ll1);
    free(ll2);
    return 0;
}