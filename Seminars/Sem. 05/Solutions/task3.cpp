#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
};

template <typename T>
void print(const Node<T> *ll) {
    while (ll) {
        cout << ll->data << ' ';
    }
    cout << '\n';
}

template <typename T>
void free(Node<T> *ll) {
    while (ll) {
        Node<T> *toDelete = ll;
        ll = ll->next;
        delete toDelete;
    }
}

template <typename T>
bool hasCycle(Node<T> *ll) {
    Node<T> *fast = ll;
    Node<T> *slow = ll;

    while (fast && fast->next && slow) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return true;
        }
    }
    return false;
}

int main() {
    Node<int> *last = new Node<int>{6, nullptr};
    Node<int> *list = new Node<int>{1,
                                    new Node<int>{2,
                                                  new Node<int>{3,
                                                                new Node<int>{4,
                                                                              new Node<int>{5,
                                                                                            last}}}}};
    last->next = list->next->next;

    cout << hasCycle(list);

    free(last);
    free(list);
    return 0;
}