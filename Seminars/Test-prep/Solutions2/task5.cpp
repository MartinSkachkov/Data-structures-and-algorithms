#include <iostream>
using namespace std;
#include <iostream>
#include <stack>
#include <initializer_list>

template <class T>
struct LinkedListNode {
    T data;
    LinkedListNode<T> *next;

    LinkedListNode(const T &elem, LinkedListNode<T> *n = nullptr) : data{elem}, next{n} {}
};

template <class T>
void printLinkedList(const LinkedListNode<T> *ll) {
    const LinkedListNode<T> *iterate = ll;

    while (iterate) {
        std::cout << iterate->data << " ";
        iterate = iterate->next;
    }

    std::cout << std::endl;
}

template <class T>
void printLinkedList(const LinkedListNode<T> *ll, void (*print)(T)) {
    const LinkedListNode<T> *iterate = ll;

    while (iterate) {
        print(iterate->data);
        iterate = iterate->next;
    }

    std::cout << std::endl;
}

template <class T>
void printLinkedList(const LinkedListNode<T> *ll, void (*print)(const T &)) {
    const LinkedListNode<T> *iterate = ll;

    while (iterate) {
        print(iterate->data);
        iterate = iterate->next;
    }

    std::cout << std::endl;
}

template <class T>
LinkedListNode<T> *fromList(const std::initializer_list<T> &l) {
    LinkedListNode<T> *toReturn = nullptr;
    LinkedListNode<T> *iter = nullptr;

    for (const auto &elem : l) {
        LinkedListNode<T> *toInsert = new LinkedListNode<T>(elem);
        if (iter == nullptr) {
            toReturn = toInsert;
            iter = toInsert;
        } else {
            iter->next = toInsert;
            iter = iter->next;
        }
    }
    return toReturn;
}

template <class T>
void freeList(LinkedListNode<T> *ll) {
    while (ll) {
        LinkedListNode<T> *toDelete = ll;
        ll = ll->next;
        delete toDelete;
    }
}

template <typename T>
void equalize(LinkedListNode<T> *ll) {
    stack<int> temp;
    LinkedListNode<T> *iter = ll;

    while (iter) {
        while (!iter->data.empty()) {
            temp.push(iter->data.top());
            iter->data.pop();
        }
        iter = iter->next;
    }

    iter = ll;

    while (!temp.empty()) {
        if (iter == nullptr) {
            iter = ll;
        }

        iter->data.push(temp.top());
        temp.pop();
        iter = iter->next;
    }
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
}

int main() {
    LinkedListNode<stack<int>> *ll = fromList(
        {std::stack<int>({1, 4}),
         std::stack<int>({6, 7, 8, 9, 5}),
         std::stack<int>({10, 11, 12}),
         std::stack<int>({1, 41}),
         std::stack<int>({6, 7, 8, 9, 5, 7, 9, 0, 10, 20, 30})});

    equalize(ll);
    printLinkedList(ll, printStack);
    freeList(ll);
}