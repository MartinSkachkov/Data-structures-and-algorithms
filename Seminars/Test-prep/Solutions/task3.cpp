#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node(const T &d = 0, Node<T> *n = nullptr) : data(d), next(n) {}
};

template <typename T>
Node<T> *removeZeroSumSublist(Node<T> *head) {
    Node<T> *ptr = head;
    Node<T> *curr = head;
    Node<T> *dummy = new Node<T>;
    dummy->next = head;
    Node<T> *prev = dummy;

    int sum = 0;
    int numOfNodesInSec = 0;
    bool deleted = false;

    while (ptr) {
        curr = ptr;
        sum = 0;
        numOfNodesInSec = 0;
        deleted = false;

        while (curr) {
            sum += curr->data;
            numOfNodesInSec++;

            if (sum == 0) {
                Node<T> *toDelete;
                Node<T> *tmp = ptr;

                ptr = curr->next;
                prev->next = ptr;

                for (int i = 0; i < numOfNodesInSec; i++) {
                    toDelete = tmp;
                    tmp = tmp->next;
                    delete toDelete;
                }
                deleted = true;
                break;
            }

            curr = curr->next;
        }
        if (!deleted) {
            ptr = ptr->next;
            prev = prev->next;
        }
    }
    return dummy->next;
}

template <typename T>
void print(const Node<T> *ll) {
    while (ll) {
        cout << ll->data << ' ';
        ll = ll->next;
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

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(-3, new Node<int>(4, nullptr)))));
    Node<int> *res = removeZeroSumSublist(ll);
    print(res);
    free(res);
    free(ll);
    return 0;
}