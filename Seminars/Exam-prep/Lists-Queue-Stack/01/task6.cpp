#include "C:\Users\Marto\Desktop\Data-structures-and-algorithms\Seminars\Sem. 04\Additional2\ll-utils.h"

template <typename T>
void arrangeOddEven(Node<T> *head) {
    // case with 0 elems, 1 elem, 2 elems
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return;
    }

    // case with more than two elems
    Node<T> *oddIt = head;
    Node<T> *evenIt = head->next, *evenHead = head->next;

    while (oddIt->next && oddIt->next->next) {
        // link only odd pos elems
        oddIt->next = oddIt->next->next;
        oddIt = oddIt->next;

        // link only even pos elems
        evenIt->next = evenIt->next->next;
        evenIt = evenIt->next;
    }

    oddIt->next = evenHead; // link the odd pos elems list to even pos elems list
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4))));
    Node<int> *ll1 = new Node<int>(1, new Node<int>(2, new Node<int>(3)));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, new Node<int>(6, new Node<int>(7)))))));
    Node<int> *ll3 = new Node<int>(11, new Node<int>(32, new Node<int>(55, new Node<int>(4, new Node<int>(50, new Node<int>(17, new Node<int>(7)))))));

    arrangeOddEven(ll);
    print(ll);

    arrangeOddEven(ll1);
    print(ll1);

    arrangeOddEven(ll2);
    print(ll2);

    arrangeOddEven(ll3);
    print(ll3);

    free(ll);
    free(ll1);
    free(ll2);
    free(ll3);
    return 0;
}