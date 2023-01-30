#include "../Easy1/ll-utils.h"
#include <algorithm> // std::max
#include <limits>    // std::numeric_limits

template <typename T>
T findLargest(Node<T> *head) { // O(n) time - O(n) memory

    if (head == nullptr)
        return -1;
    else
        return std::max(head->data, findLargest(head->next));
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(2, new Node<int>(4, new Node<int>(4, new Node<int>(1, new Node<int>(5, new Node<int>(2)))))))));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(1, new Node<int>(2, new Node<int>(4, new Node<int>(1, new Node<int>(7, new Node<int>(1, new Node<int>(8, new Node<int>(1, new Node<int>(1))))))))))));
    Node<int> *ll3 = nullptr;

    print(ll);
    cout << findLargest(ll) << '\n';

    print(ll2);
    cout << findLargest(ll2) << '\n';

    print(ll3);
    cout << findLargest(ll3) << '\n';

    free(ll);
    free(ll2);
    return 0;
}