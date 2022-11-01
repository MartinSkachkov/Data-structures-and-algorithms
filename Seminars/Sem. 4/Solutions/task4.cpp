#include "LL_utils.h"
#include <iostream>

// this solution skips some cases :(

bool isEven(int num) {
    return num % 2 == 0;
}

template <typename T>
int numberOfRotations(LLNode<T> *head) {
    int counter = 1;
    while (head->mNext) {
        head = head->mNext;
        counter++;
    }
    return counter / 2;
}

template <typename T>
void moveTheHeadToBack(LLNode<T> *&head, LLNode<T> *&previous) {
    while (head->mNext) {
        previous = head;
        head = head->mNext;
    }
}

template <typename T>
void rotation(LLNode<T> *&head, LLNode<T> *&tmp, LLNode<T> *&previous) {
    LLNode<T> *next = tmp->mNext;
    tmp->mNext = head;
    tmp = next;
    head->mNext = tmp;
    previous->mNext = nullptr;
}

template <typename T>
void reorder(LLNode<T> *&head) {
    int numOfRot = isEven(numberOfRotations(head)) ? numberOfRotations(head) - 1 : numberOfRotations(head);
    LLNode<T> *tmp = head;
    LLNode<T> *previous = nullptr;

    for (size_t i = 0; i < numOfRot; i++) {
        moveTheHeadToBack(head, previous);
        rotation(head, tmp, previous);
    }
}

int main() {
    LLNode<int> *head = new LLNode<int>(1, new LLNode<int>(2, new LLNode<int>(3, new LLNode<int>(4, new LLNode<int>(5, new LLNode<int>(6))))));
    LLNode<int> *beginningOfTheList = head;
    printLL(head);
    reorder(head);
    printLL(beginningOfTheList);
    free(beginningOfTheList);
    return 0;
}