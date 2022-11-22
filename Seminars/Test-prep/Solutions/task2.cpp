#include <iostream>
#include <stack>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
};

template <typename T>
void print(const Node<T> *ll) {
    while (ll) {
        cout << ll->data;
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

template <typename T>
Node<T> *findMid(Node<T> *head) {
    Node<T> *slowPtr = head;
    Node<T> *fastPtr = head;

    while (fastPtr && fastPtr->next) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}

template <typename T>
void pushToStack(stack<T> &s, Node<T> *head) {
    Node<T> *mid = findMid(head);
    while (mid) {
        s.push(mid->data);
        mid = mid->next;
    }
}

template <typename T>
bool isPalindrome(stack<T> &s, Node<T> *head) {
    // 1 elem
    if (head->next == nullptr) {
        return true;
    }

    // 2 elems
    if (head->next->next == nullptr) {
        if (head->data == head->next->data) {
            return true;
        } else {
            return false;
        }
    }

    // more than 2 elems
    Node<T> *it = head;
    Node<T> *mid = findMid(head);
    while (it != mid) {
        if (it->data == s.top()) {
            s.pop();
        }
        it = it->next;
    }

    // case for odd length palindrome
    if (!s.empty()) {
        if (s.top() == mid->data) {
            s.pop();
        } else {
            return false;
        }
    }

    if (s.empty() && it == mid) {
        return true;
    }
    return false;
}

template <typename T>
void emptyStack(stack<T> &s) {
    while (!s.empty()) {
        s.pop();
    }
}

int main() {
    Node<int> *odd = new Node<int>{1, new Node<int>{2, new Node<int>{3, new Node<int>{2, new Node<int>{1, nullptr}}}}};
    Node<int> *even = new Node<int>{1, new Node<int>{2, new Node<int>{2, new Node<int>{1, nullptr}}}};
    Node<int> *notPal = new Node<int>{1, new Node<int>{2, nullptr}};
    stack<int> s;

    pushToStack(s, odd);
    cout << isPalindrome(s, odd) << '\n';
    emptyStack(s);

    pushToStack(s, even);
    cout << isPalindrome(s, even) << '\n';
    emptyStack(s);

    pushToStack(s, notPal);
    cout << isPalindrome(s, notPal) << '\n';
    emptyStack(s);

    free(odd);
    free(even);
    free(notPal);
    return 0;
}