#include "dll-utils.h"

template <typename T>
void deleteOddPos(Node<T> *head) {
    // empty list or one element list
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // more elements
    Node<T> *it = head;
    Node<T> *toDel = nullptr;
    bool oddPos = false;

    while (it != nullptr) {
        if (oddPos) {
            if (it->next == nullptr) { // last element is on oddPos
                toDel = it;
                it->prev->next = nullptr;

                delete toDel;
                break;
            }

            toDel = it;
            it->prev->next = it->next;
            it->next->prev = it->prev;
            it = it->next;

            delete toDel;
            oddPos = !oddPos;
            continue;
        }

        oddPos = !oddPos;
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
    Node<int> *n8 = new Node<int>(12);

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
    n7->next = n8;
    n8->prev = n7;

    Node<int> *single = new Node<int>(1);

    deleteOddPos(n1);
    print(n1);

    deleteOddPos(single);
    print(single);

    free(n1);
    free(single);
    return 0;
}