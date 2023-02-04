#include "C:\Users\Marto\Desktop\Data-structures-and-algorithms\Seminars\Sem. 04\Additional2\ll-utils.h"

template <typename T>
Node<T> *insertSortedCycle(Node<T> *head, T data) {
    Node<T> *prev = head;
    Node<T> *curr = head->next;

    while (curr != head) {
        // ordinary insert
        if (prev->data <= data && curr->data >= data) {
            break;
        }

        // insert an element before the cycle
        if (prev->data > curr->data && (prev->data <= data || curr->data >= data)) {
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    prev->next = new Node<T>(data, curr);
    return head;
}

int main() {
    Node<int> *head2 = new Node<int>(1, nullptr);
    Node<int> *head1 = new Node<int>(4, head2);
    Node<int> *head = new Node<int>(3, head1);
    head2->next = head;

    insertSortedCycle(head, 2);
    print(head);

    free(head);
    return 0;
}