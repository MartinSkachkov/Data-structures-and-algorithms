#include "../Easy1/ll-utils.h"

template <typename T>
void deleteNode(Node<T> *&ll, int key) {
    Node<T> *it = ll;

    // empty list
    if (it == nullptr) {
        cerr << "Can't delete an element from an empty list!";
    } else if (it->next == nullptr && key == it->data) { // only one element
        delete it;
        it = nullptr;
        cout << "Empty list!";
    } else { // more than one
        Node<T> *prev = nullptr;

        while (it != nullptr) {
            // we found the desired element
            if (it->data == key) {
                Node<T> *toDel = it;
                it = it->next;
                prev->next = it;
                delete toDel;
                return;
            }

            prev = it;
            it = it->next;
        }
    }
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    deleteNode(ll, 3);
    deleteNode(ll, 5);
    print(ll);

    free(ll);
    return 0;
}