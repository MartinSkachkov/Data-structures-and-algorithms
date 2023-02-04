#include "dll-utils.h"

template <typename T>
void deleteKeyNodes(Node<T> *&head, const T &key) {
    // empty list
    if (head == nullptr) {
        return;
    }

    // one node list
    if (head->next == nullptr && head->data == key) {
        delete head;
        head = nullptr;
        return;
    }

    // more than one node
    Node<T> *it = head;
    while (it != nullptr) {
        if (it->data == key) {
            Node<T> *toDel = it;
            it->prev->next = it->next;
            if (it->next == nullptr) {
                delete toDel;
                break;
            } else {
                it->next->prev = it->prev;
                it = it->next;
                delete toDel;
                continue;
            }
        }
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

    deleteKeyNodes(n1, 4);
    print(n1);

    deleteKeyNodes(single, 3);
    print(single);

    free(n1);
    free(single);
    return 0;
}