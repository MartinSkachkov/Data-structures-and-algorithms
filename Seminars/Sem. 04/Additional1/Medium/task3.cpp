#include "../Easy1/ll-utils.h"

template <typename T>
void removeDuplicates(Node<T> *head) {

    while (head != nullptr) {
        Node<T> *it = head->next;
        Node<T> *prev = head;

        while (it != nullptr) {
            // remuving duplicates
            if (head->data == it->data) {
                Node<T> *nextEl = it->next;
                prev->next = nextEl;
                delete it;
                it = nextEl;
                continue;
            }

            prev = it;
            it = it->next;
        }

        head = head->next;
    }
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(1, new Node<int>(3, new Node<int>(2, new Node<int>(4, new Node<int>(3, new Node<int>(5, new Node<int>(2)))))))));
    Node<int> *ll1 = new Node<int>(1, new Node<int>(1, new Node<int>(1)));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    Node<int> *ll3 = nullptr;

    removeDuplicates(ll);
    print(ll);

    removeDuplicates(ll1);
    print(ll1);

    removeDuplicates(ll2);
    print(ll2);

    removeDuplicates(ll3);
    print(ll3);

    free(ll);
    free(ll1);
    free(ll2);
    return 0;
}