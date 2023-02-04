#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node<T> *random;
    Node(const T &d, Node<T> *n = nullptr, Node<T> *r = nullptr) : data(d), next(n), random(r) {}
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
        cout << "Curr data: " << ll->data << ' ' << "Random data: " << ll->random->data << '\n';
        ll = ll->next;
    }
}

///////////////////////////////////////////////////////////

template <typename T>
Node<T> *findMaxNode(Node<T> *ll) {
    int maxData = INT_MIN;
    Node<T> *maxNode = nullptr;

    while (ll != nullptr) {
        if (ll->data > maxData) {
            maxData = ll->data;
            maxNode = ll;
        }

        ll = ll->next;
    }

    return maxNode;
}

// Input: 5(Ø) -> 10(Ø) -> 7(Ø) -> 9(Ø) -> 4(Ø) -> 3(Ø) -> Ø
// Output: 5(10) -> 10(9) -> 7(9) -> 9(4) -> 4(3) -> 3(Ø) -> Ø

template <typename T>
void findMaxRandom(Node<T> *head) {
    while (head != nullptr) {
        head->random = findMaxNode(head->next);
        head = head->next;
    }
}

int main() {
    Node<int> *ll1 = new Node<int>(5, new Node<int>(10, new Node<int>(7, new Node<int>(9, new Node<int>(4, new Node<int>(3))))));
    Node<int> *ll2 = new Node<int>(1, new Node<int>(2, new Node<int>(3)));

    findMaxRandom(ll1);
    print(ll1);

    free(ll1);
    free(ll2);
    return 0;
}