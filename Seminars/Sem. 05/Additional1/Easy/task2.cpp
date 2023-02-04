#include "dll-utils.h"

template <typename T>
void deleteEvenPos(Node<T> *&head) {
    // empty list
    if (head == nullptr) {
        return;
    }

    // one element in the list
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // more than one elements
    Node<T> *it = head;
    head = head->next; // we will save only the elements on even positions so the new head will be the second element

    bool evenPos = true;
    Node<T> *toDel = nullptr;

    while (it != nullptr) {
        if (evenPos) {
            // deleting the element at pos 0
            if (it->prev == nullptr) {
                toDel = it;
                it->next->prev = nullptr;
                it = it->next;

                delete toDel;
                evenPos = !evenPos;
                continue;
            }

            // deleting the last even pos element
            if (it->next == nullptr) {
                toDel = it;
                it->prev->next = nullptr;
                it = it->next;

                delete toDel;
                evenPos = !evenPos;
                continue;
            }

            // inner deletion in the list
            toDel = it;
            it->prev->next = it->next;
            it->next->prev = it->prev;
            it = it->next;

            delete toDel;
            evenPos = !evenPos;
            continue;
        }

        evenPos = !evenPos;
        it = it->next;
    }
}

int main() {
    Node<int> *n1 = new Node<int>(1);
    Node<int> *n2 = new Node<int>(2);
    Node<int> *n3 = new Node<int>(5);
    Node<int> *n4 = new Node<int>(4);
    Node<int> *n5 = new Node<int>(5);
    Node<int> *n6 = new Node<int>(4);
    Node<int> *n7 = new Node<int>(4);

    // linking the nodes
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;
    n5->next = n6;
    n6->prev = n5;
    n6->next = n7;
    n7->prev = n6;

    Node<int> *single = new Node<int>(1);

    deleteEvenPos(n1);
    print(n1);

    deleteEvenPos(single);
    print(single);

    free(n1);
    free(single);
    return 0;
}