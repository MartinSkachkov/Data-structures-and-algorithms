#include "../Easy1/ll-utils.h"

template <typename T>
void removeEvenPos(Node<T> *&ll) {
    Node<T> *it = ll;
    bool evenPos = false;

    if (it == nullptr) { // no elements
        cerr << "Nothing to remove from an empty list!";
    } else if (it->next == nullptr) { // one element
        cout << "Removed the only element. Empty list!";
        delete it;
    } else { // more than one elements
        // if we've reached the else statement this guarantees that we will have at least two elements
        // so we will start from pos = 1
        ll = ll->next;
        Node<T> *prev = nullptr;

        while (it != nullptr) {
            evenPos = !evenPos;

            if (evenPos) {
                // deleting the node
                Node<T> *toDel = it;
                it = it->next;
                delete toDel;

                // linking the previous to the next
                if (prev != nullptr)
                    prev->next = it;

                continue;
            }

            prev = it;
            it = it->next;
        }
    }
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    Node<int> *ll1 = new Node<int>(1, new Node<int>(2, new Node<int>(3)));

    removeEvenPos(ll);
    print(ll);

    removeEvenPos(ll1);
    print(ll1);

    free(ll);
    free(ll1);
    return 0;
}