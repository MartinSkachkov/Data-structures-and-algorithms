#include <iostream>
#include <stack>
using namespace std;

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
Node<T> *findMid(Node<T> *ll) {
    Node<T> *fast = ll;
    Node<T> *slow = ll;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

template <typename T>
void pushToStack(stack<T> &s, Node<T> *ll) {
    Node<T> *mid = findMid(ll);

    while (mid) {
        s.push(mid->data);
        mid = mid->next;
    }
}

template <typename T>
bool isPalindrome(stack<T> &s, Node<T> *ll) {
    if (ll == nullptr) {
        return false;
    }
    if (ll->next == nullptr) {
        return true;
    }
    if (ll->next->next == nullptr) {
        if (ll->data == ll->next->data) {
            return true;
        } else {
            return false;
        }
    }

    Node<T> *iter = ll;
    Node<T> *mid = findMid(ll);

    while (iter != mid) {
        if (iter->data == s.top()) {
            s.pop();
        }
        iter = iter->next;
    }

    if (!s.empty()) {
        if (s.top() == mid->data) {
            s.pop();
        } else {
            return false;
        }
    }
    if (s.empty() && iter == mid) {
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

    freeL(odd);
    freeL(even);
    freeL(notPal);
    return 0;
}