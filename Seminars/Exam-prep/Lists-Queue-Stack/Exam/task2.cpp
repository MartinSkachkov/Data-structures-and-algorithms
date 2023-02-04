#include <exception>
#include <iostream>

template <typename T>
struct Node {
    T value;
    Node<T> *next;
    Node(T value, Node *next = nullptr) : value(value), next(next) {}
};

template <typename T>
void print(Node<T> *head) {
    while (head) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << '\n';
}

template <typename T>
void deleteList(Node<T> *head) {
    while (head) {
        Node<int> *del = head;
        head = head->next;
        delete del;
    }
}

template <typename T>
bool isBalanced(Node<T> *head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        throw "less than 3 elements list!";
        return false;
    }

    // 3 or more elements
    Node<T> *prev = head;
    Node<T> *curr = head->next;
    Node<T> *next = curr->next;

    while (next != nullptr) {
        // if the condition for balanced list is broken then return false
        if (!(curr->value == (prev->value + next->value))) {
            return false;
        }

        prev = curr;
        curr = next;
        next = curr->next;
    }

    return true;
}

template <typename T>
bool predicate(T prevData, T currData, T nextData) {
    return currData == prevData + nextData;
}

template <typename T>
bool makeTotal(Node<T> *&head) {
    if (isBalanced(head)) {
        return true;
    }

    Node<T> *prev = head;
    Node<T> *curr = head->next;
    Node<T> *next = curr->next;

    while (next != nullptr) {
        if (predicate(prev->value, curr->value, next->value)) {
            prev->next = next; // link the prevoius node to the next one
            delete curr;       // remove the current

            // previuos is not changed, we just increment the curr & next ptrs
            curr = next;
            next = curr->next;
            continue;
        }

        prev = curr;
        curr = next;
        next = curr->next;
    }

    return false;
}

int main() {
    Node<int> *head = new Node<int>(1, new Node<int>(-4, new Node<int>(-5, new Node<int>(-1, new Node<int>(4)))));
    print(head);
    std::cout << std::boolalpha << makeTotal(head) << '\n';
    print(head);

    Node<int> *head1 = new Node<int>(10, new Node<int>(5, new Node<int>(-5, new Node<int>(-15, new Node<int>(2)))));
    print(head1);
    std::cout << std::boolalpha << makeTotal(head1) << '\n';
    print(head1);

    deleteList(head);
    deleteList(head1);
}