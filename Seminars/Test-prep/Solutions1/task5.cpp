#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node(const T &d, Node<T> *n) : data(d), next(n) {}
};

template <typename T>
void print(const Node<T> *ll) {
    const Node<T> *tmp = ll;
    do {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    } while (tmp != ll);

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
Node<T> *insert(Node<T> *head, int val) {
    Node<T> *prev = head;
    Node<T> *curr = head->next;

    while (head != curr) {
        if (prev->data <= val && curr->data >= val) {
            break;
        }
        if (prev->data > curr->data && (prev->data <= val || curr->data >= val)) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    prev->next = new Node<T>{val, curr};
    return head;
}

int main() {
    Node<int> *head2 = new Node<int>(1, nullptr);
    Node<int> *head1 = new Node<int>(4, head2);
    Node<int> *head = new Node<int>(3, head1);
    head2->next = head;

    print(insert(head, 2));
    return 0;
}