#include "../Easy1/ll-utils.h"

template <typename T>
void swapValues(Node<T> *ll) {
    Node<T> *fast = ll->next;

    // empty list
    if (ll == nullptr) {
        cerr << "Can't swap values in empty list!";
        return;
    } else if (ll->next == nullptr) { // only one element
        return;
    } else { // more than one element
        // swapping two node values
        while (fast != nullptr && ll != nullptr) {
            T tmp = ll->data;
            ll->data = fast->data;
            fast->data = tmp;

            ll = fast->next;
            fast = fast->next->next;
        }
    }
}

int main() {
    Node<int> *ll = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4, new Node<int>(5)))));
    swapValues(ll);
    print(ll);

    free(ll);
    return 0;
}