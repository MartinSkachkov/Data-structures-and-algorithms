#include "ll-utils.h"

template <typename T>
void reverseSpecifiedPortion(Node<T> *&head, int startPos, int endPos) {
    if (head == nullptr || startPos > endPos) {
        return;
    }

    Node<T> *subHead = head;
    Node<T> *subTail = head;
    Node<T> *prevNodeBeg = nullptr, *prevNodeEnd = nullptr, *next = nullptr;

    int counter = 0;
    // put a pointer to the starting position
    while (subHead != nullptr && counter != startPos) {
        prevNodeBeg = subHead;
        subHead = subHead->next;
        counter++;
    }

    // put a pointer to the ending position
    counter = 0;
    while (subTail != nullptr && counter != endPos) {
        prevNodeEnd = subTail;
        subTail = subTail->next;
        counter++;
    }

    if (subTail == nullptr && counter != 0) {
        cout << "Sublist length is too big!";
        return;
    } else if (subTail == nullptr && counter == 0) {
        subTail = prevNodeEnd;
        next = nullptr;
    } else {
        next = subTail->next;
        subTail->next = nullptr;
    }

    // reversing the sublist
    Node<T> *revPrev = nullptr, *revNext = nullptr;

    while (subHead != nullptr) {
        revNext = subHead->next;
        subHead->next = revPrev;
        revPrev = subHead;
        subHead = revNext;
    }

    subHead = revPrev;

    // link the reversed sublist to the previous and next nodes in the original
    if (prevNodeBeg == nullptr) {
        subTail = head;
        subTail->next = next;
        head = subHead;
    } else {
        subTail = prevNodeBeg->next;
        prevNodeBeg->next = subHead;
        subTail->next = next;
    }
}

int main() {
    Node<int> *ll1 = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5, new Node<int>(6, new Node<int>(7)))))));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(3)));

    reverseSpecifiedPortion(ll1, 3, 6);
    print(ll1);

    free(ll1);
    free(ll2);
    return 0;
}