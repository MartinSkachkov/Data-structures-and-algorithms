#include "../Easy1/ll-utils.h"

template <typename T>
bool check(Node<T> *list, T key) {
    while (list != nullptr) {
        if (list->data == key) {
            return true;
        }
        list = list->next;
    }
    return false;
}

template <typename T>
void removeLastOccurance(Node<T> *&head, T key) {
    // empty list
    if (head == nullptr) {
        return;
    }

    // matching the first element
    bool hasMore = check(head->next, key);
    if (head->data == key && !hasMore) {
        Node<T> *toDel = head;
        head = head->next;
        delete toDel;
        return;
    }

    // case the key doesn't exist
    if (!hasMore) {
        return;
    }

    // has more elements with the value of the key
    Node<T> *it = head->next;
    Node<T> *prev = head;

    Node<T> *toDel = nullptr, *prevEl = nullptr, *nextEl = nullptr;

    while (it != nullptr) {

        // mark the last node we search for
        if (it->data == key) {
            nextEl = it->next;
            toDel = it;
            prevEl = prev;
        }

        prev = it;
        it = it->next;
    }

    // delete the node and link the prev & next
    prevEl->next = nextEl;
    delete toDel;
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(1, new Node<int>(3, new Node<int>(2, new Node<int>(4, new Node<int>(3, new Node<int>(5, new Node<int>(2)))))))));
    Node<int> *ll1 = new Node<int>(1, new Node<int>(1, new Node<int>(1)));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(2, new Node<int>(5)))));
    Node<int> *ll3 = nullptr;

    removeLastOccurance(ll, 5);
    print(ll);

    removeLastOccurance(ll, 2);
    print(ll);

    removeLastOccurance(ll, 1);
    print(ll);

    removeLastOccurance(ll1, 1);
    print(ll1);

    removeLastOccurance(ll2, 8);
    print(ll2);

    removeLastOccurance(ll3, 2);
    print(ll3);

    free(ll);
    free(ll1);
    free(ll2);
    return 0;
}