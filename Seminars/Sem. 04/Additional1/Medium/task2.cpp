#include "../Easy1/ll-utils.h"
#include <assert.h>

template <typename T>
void rotateKLeft(Node<T> *&head, int k) {
    if (k <= 0 || head == nullptr) {
        return;
    }

    Node<T> *it = head;

    while (it->next != nullptr) {
        it = it->next;
    }

    Node<T> *newHead = head->next;
    it->next = head;
    head->next = nullptr;
    head = newHead;

    rotateKLeft(head, k - 1);
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    Node<int> *ll1 = nullptr;

    rotateKLeft(ll, 6);
    print(ll);
    rotateKLeft(ll, 2);
    print(ll);

    rotateKLeft(ll1, 0);
    print(ll1);

    free(ll);
    free(ll1);
    return 0;
}