D

template <typename T>
struct Node {
    T data;
    Node<T> *next;
};

template <typename T>
void freeL(Node<T> *ll) {
    while (ll) {
        Node<T> *toDelete = ll;
        ll = ll->next;
        delete toDelete;
    }
}

template <typename T>
bool isPalRec(Node<T> *&start, Node<T> *&end) {
    if (end == nullptr) {
        return true;
    }

    bool res = isPalRec(start, end->next) && (start->data == end->data);
    start = start->next;
    return res;
}

template <typename T>
bool isPal(Node<T> *ll) {
    if (ll == nullptr) {W
        return true;
    }

    Node<T> *start = ll;
    Node<T> *end = ll;

    return isPalRec(start, end);
}

int main() {
    Node<int> *odd = new Node<int>{1, new Node<int>{2, new Node<int>{3, new Node<int>{2, new Node<int>{1, nullptr}}}}};
    Node<int> *even = new Node<int>{1, new Node<int>{2, new Node<int>{2, new Node<int>{1, nullptr}}}};
    Node<int> *notPal = new Node<int>{1, new Node<int>{2, nullptr}};

    cout << isPal(odd);
    cout << isPal(even);
    cout << isPal(notPal);

    freeL(odd);
    freeL(even);
    freeL(notPal);
    return 0;
}