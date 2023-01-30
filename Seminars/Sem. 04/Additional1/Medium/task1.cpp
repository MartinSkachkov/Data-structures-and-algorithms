#include "../Easy1/ll-utils.h"

// 6, 10, 8, 15
// 15, 10, 8, 6
template <typename T>
void swapHeadTail(Node<T> *&head) {
    if (head == nullptr) {
        cerr << "Empty list!";
        return;
    }

    if (head->next == nullptr) {
        return;
    }

    Node<T> *it = head;
    Node<T> *prev = nullptr;

    // we will be at the last node
    while (it->next != nullptr) {
        prev = it;     // 8
        it = it->next; // 15
    }

    Node<T> *tmp = head->next; // 6
    prev->next = head;         // link 8 with 6
    head->next = it->next;     // link 6 with NULL
    it->next = tmp;            // link 15 with 10
    head = it;                 // set the start point
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    Node<int> *ll1 = nullptr;

    swapHeadTail(ll);
    print(ll);

    swapHeadTail(ll1);
    print(ll1);

    free(ll);
    free(ll1);
    return 0;
}