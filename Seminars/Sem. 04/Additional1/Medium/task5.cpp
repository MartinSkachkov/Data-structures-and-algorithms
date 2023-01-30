#include "../Easy1/ll-utils.h"

template <typename T>
int count(Node<T> *head, T key) {
    int c = 0;

    while (head != nullptr) {
        if (head->data == key) {
            c++;
        }

        head = head->next;
    }

    return c;
}

template <typename T>
void moveToBack(Node<T> *&head, T key) {
    if (head == nullptr) {
        return;
    }

    Node<T> *it = head, *tail = nullptr;

    // find tail
    while (it != nullptr) {
        tail = it;
        it = it->next;
    }

    // reset the iterator
    it = head;
    bool startWithKeyVal = true;
    int occurancesOfKey = count(head, key);

    while (it != nullptr && occurancesOfKey != 0) {
        if (it->data == key) {
            Node<T> *toPush = it;
            it = it->next; // move the iterator
            toPush->next = nullptr;

            tail->next = toPush;
            tail = tail->next;
            occurancesOfKey--;

            if (startWithKeyVal) {
                head = it;
            }

            continue;
        }

        startWithKeyVal = false;
        it = it->next;
    }
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(2, new Node<int>(4, new Node<int>(4, new Node<int>(1, new Node<int>(5, new Node<int>(2)))))))));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(1, new Node<int>(2, new Node<int>(4, new Node<int>(1, new Node<int>(7, new Node<int>(1, new Node<int>(8, new Node<int>(1, new Node<int>(1))))))))))));
    Node<int> *ll3 = nullptr;

    moveToBack(ll, 1);
    print(ll);

    moveToBack(ll2, 1);
    print(ll2);

    moveToBack(ll3, 2);
    print(ll3);

    free(ll);
    free(ll2);
    return 0;
}