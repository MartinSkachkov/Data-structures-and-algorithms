#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node(const T &d, Node<T> *n = nullptr) : data(d), next(n) {}
};

template <typename T>
void free(Node<T> *ll) {
    while (ll != nullptr) {
        Node<T> *toDel = ll;
        ll = ll->next;
        delete toDel;
    }
}

template <typename T>
void print(const Node<T> *ll) {
    while (ll != nullptr) {
        cout << ll->data << ' ';
        ll = ll->next;
    }
    cout << '\n';
}

template <typename T>
T findMid(Node<T> *head) {
    if (head == nullptr) {
        return INT_MIN;
    }

    Node<T> *fast = head;
    Node<T> *slow = head;

    while (slow && fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

int main() {
    Node<int> *ll = new Node<int>(4, new Node<int>(2, new Node<int>(1, new Node<int>(3, new Node<int>(8, new Node<int>(13))))));
    Node<int> *ll2 = new Node<int>(-1, new Node<int>(5, new Node<int>(3, new Node<int>(4, new Node<int>(0)))));
    Node<int> *ll3 = new Node<int>(-1);
    Node<int> *n = nullptr;

    cout << findMid(ll) << '\n';

    cout << findMid(ll2) << '\n';

    cout << findMid(ll3) << '\n';

    cout << findMid(n) << '\n';

    free(ll);
    free(ll2);
    free(ll3);
    return 0;
}