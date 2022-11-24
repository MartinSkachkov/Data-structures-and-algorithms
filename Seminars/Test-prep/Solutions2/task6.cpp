#include <initializer_list>
#include <iostream>
using namespace std;
#include <queue>

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

using ListNode = LinkedListNode<std::queue<int>>;

void concatenate(std::queue<int> &to, std::queue<int> &from) {
    while (!from.empty()) {
        to.push(from.front());
        from.pop();
    }
}

bool all(std::queue<int> q, bool (*pred)(int)) {
    while (!q.empty()) {
        if (!pred(q.front())) {
            return false;
        }
        q.pop();
    }

    return true;
}

void concatenateSimilarQueues(ListNode *ll, bool (*pred)(int)) {
    if (!ll || !ll->next)
        return;

    ListNode *iter = ll;

    while (iter && iter->next) {
        if (all(iter->data, pred)) {
            while (iter->next && all(iter->next->data, pred)) {
                ListNode *toDelete = iter->next;
                iter->next = iter->next->next;
                concatenate(iter->data, toDelete->data);

                delete toDelete;
            }
        }
        iter = iter->next;
    }
}

void printQueue(std::queue<int> q) {
    std::cout << "[ ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << " ]" << std::endl;
}

int main() {
    ListNode *ll = fromList({std::queue<int>({1, 2, 3}),
                             std::queue<int>({4, 5, 6, 7, 8, 8, 9}),
                             std::queue<int>({12, 14, 16}),
                             std::queue<int>({101, 102}),
                             std::queue<int>({103, 104, 105})});

    concatenateSimilarQueues(
        ll,
        [](int x) -> bool { return x < 10 || x > 100; });

    printLinkedList(ll, printQueue);
    freeList(ll);
}