#include "C:\Users\Marto\Desktop\Data-structures-and-algorithms\Seminars\Sem. 04\Additional2\ll-utils.h"

template <typename T>
void freeSublist(Node<T> *&prev, Node<T> *&head, Node<T> *&end) {
    while (head != end) {
        Node<T> *toDel = head;
        head = head->next;
        delete toDel;
    }

    if (prev == nullptr) {
        delete end;
    } else {
        prev->next = end->next;
        delete end;
    }
}

template <typename T>
Node<T> *zeroSumConsec(Node<T> *&head) {
    // empty list
    if (head == nullptr) {
        return head;
    }

    // one node with data 0
    if (head->next == nullptr && head->data == 0) {
        delete head;
        head = nullptr;
        return head;
    }

    Node<T> *headCopy = head;

    // more than one node
    bool deleted = false;
    Node<T> *prev = nullptr;

    while (headCopy != nullptr) {
        Node<T> *it = headCopy->next;
        int sum = headCopy->data;
        deleted = false;

        while (it != nullptr) {
            sum += it->data;

            if (sum == 0) {
                Node<T> *newHead = it->next;
                freeSublist(prev, headCopy, it);
                deleted = true;

                if (prev == nullptr) {
                    head = newHead;
                }

                headCopy = newHead;
                break;
            }

            it = it->next;
        }

        if (deleted) {
            continue; // we have moved the pointer
        } else {
            prev = headCopy;
            headCopy = headCopy->next;
        }
    }

    return head;
}

int main() {
    Node<int> *ll1 = new Node<int>(1, new Node<int>(2, new Node<int>(-3, new Node<int>(3, new Node<int>(2, new Node<int>(6))))));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(-3, new Node<int>(-2)))));

    Node<int> *res = zeroSumConsec(ll2);
    print(res);

    free(ll1);
    free(ll2);
    return 0;
}