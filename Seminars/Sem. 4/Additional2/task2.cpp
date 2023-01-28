#include "ll-utils.h"

template <typename T>
bool hasCycle(const Node<T> *head) {
    const Node<T> *slow = head;
    const Node<T> *fast = head;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    Node<int> *ll = new Node<int>(3, new Node<int>(2, new Node<int>(0, new Node<int>(-4))));
    cout << hasCycle(ll);

    Node<int> *ll1 = new Node<int>(3, new Node<int>(2));
    cout << hasCycle(ll1);

    Node<int> *ll2 = new Node<int>(1);
    cout << hasCycle(ll2);

    free(ll);
    free(ll1);
    free(ll2);
    return 0;
}