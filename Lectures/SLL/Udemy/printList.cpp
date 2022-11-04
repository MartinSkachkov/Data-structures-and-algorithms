#include <iostream>

template <typename T>
struct Node {
    T mData;
    Node<T> *mNext;
    Node(const T &data = -1, Node<T> *next = nullptr) : mData(data), mNext(next) {}
};

//!!! ALL FUNCTIONS ARE TAKING A **COPY** OF THE HEAD PTR SO THERE IS NO NEED TO MAKE A TMP NODE PTR !!!

template <typename T>
void printNodes(const Node<T> *head) {
    while (head != nullptr) {
        std::cout << head->mData << ' ';
        head = head->mNext;
    }
}

template <typename T>
void printNodesFor(const Node<T> *head) {
    for (const Node<T> *i = head; i != nullptr; i = i->mNext) {
        std::cout << i->mData << ' ';
    }
}

template <typename T>
void printNodesRec(const Node<T> *head) {
    // base case is when we are at the end of the list, then print the last element and return
    if (head->mNext == nullptr) {
        std::cout << head->mData << ' ';
        return;
    }
    std::cout << head->mData << ' ';
    printNodesRec(head->mNext);

    /* this is in a reverse order
    if (head == nullptr) {
        return;
    }
    printNodesRec(head->mNext);
    std::cout << head->mData;*/
}

template <typename T>
Node<T> *find(Node<T> *head, T value) {
    while (head->mNext != nullptr) {
        if (head->mData == value) {
            return head;
        }
        head = head->mNext;
    }
    return NULL;
}

template <typename T>
void free(Node<T> *head) {
    Node<T> *tmp = nullptr;
    while (head) {
        tmp = head;
        head = head->mNext;
        delete tmp;
    }
}

template <typename T>
T getNthElem(const Node<T> *head, int indx) {
    int ctr = 0;
    while (head) {
        if (ctr == indx) {
            return head->mData;
        }
        head = head->mNext;
        ctr++;
    }
    return (T)NULL;
}

int main() {
    Node<int> *newNode = new Node<int>(1, new Node<int>(2, new Node<int>(3, new Node<int>(4))));
    printNodes(newNode);
    std::cout << '\n';
    printNodesRec(newNode);
    std::cout << '\n';
    printNodesFor(newNode);
    std::cout << '\n';
    std::cout << find(newNode, 3);
    std::cout << '\n';
    std::cout << getNthElem(newNode, 2);
    free(newNode);
    return 0;
}