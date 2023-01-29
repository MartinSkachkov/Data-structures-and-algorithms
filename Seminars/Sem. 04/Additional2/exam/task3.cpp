#include <assert.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
};

enum StackType {
    Even,
    Odd,
    Mixed
};

typedef Node<stack<int>> StackNode;

StackType checkType(stack<int> s) {
    bool even = true, odd = true;

    while (!s.empty()) {
        if (!(s.top() % 2 == 0) && even) {
            even = false;
        }
        if (!(s.top() % 2 != 0) && odd) {
            odd = false;
        }
        s.pop();
    }

    if (even) {
        return Even;
    } else if (odd) {
        return Odd;
    } else {
        return Mixed;
    }
}

StackNode *concatSimilarStackElems(StackNode *head) {
    StackNode *nextEl = head->next;
    StackNode *start = head;

    if (head == nullptr) { // zero elements
        return nullptr;
    } else if (nextEl == nullptr) { // one element
        return head;
    } else { // more elements
        while (head != nullptr && nextEl != nullptr) {
            StackType currSType = checkType(head->data);
            StackType nextSType = checkType(nextEl->data);

            if (currSType == nextSType && currSType != Mixed) { // odd & even case
                // typedefing
                stack<int> &from = nextEl->data;
                stack<int> &to = head->data;
                vector<int> tmp;

                // moving the elements from nextEl to vector
                while (!from.empty()) {
                    tmp.push_back(from.top());
                    from.pop();
                }

                // adding the elements the vector to the currEl
                while (!tmp.empty()) {
                    to.push(tmp.back());
                    tmp.pop_back();
                }

                // jump over the empty stack node to continue the iterations
                head->next = nextEl->next;
                head = head->next;

                // delete the empty stack node
                StackNode *toDel = nextEl;
                nextEl = nextEl->next->next;
                delete toDel;

            } else { // mixed case
                nextEl = nextEl->next;
                head = head->next;
            }
        }
    }

    return start;
}

void printStackData(vector<int> &stackData) {
    while (!stackData.empty()) {
        cout << stackData.back() << ' ';
        stackData.pop_back();
    }
    cout << '\n';
}

void printStack(stack<int> s) {
    vector<int> stackData;

    while (!s.empty()) {
        stackData.push_back(s.top());
        s.pop();
    }
    printStackData(stackData);
}

void print(StackNode *ll) {
    StackNode *it = ll;

    while (it != nullptr) {
        printStack(it->data);
        it = it->next;
        cout << '\n';
    }
}

void free(StackNode *ll) {
    while (ll != nullptr) {
        StackNode *toDel = ll;
        ll = ll->next;
        delete toDel;
    }
}

int main() {
    stack<int> s1;
    s1.push(2);
    s1.push(4);
    s1.push(6);
    cout << checkType(s1) << '\n';

    stack<int> s2;
    s2.push(8);
    s2.push(0);
    cout << checkType(s2) << '\n';

    stack<int> s3;
    s3.push(5);
    s3.push(7);
    cout << checkType(s3) << '\n';

    stack<int> s4;
    s4.push(9);
    s4.push(1);
    cout << checkType(s4) << '\n';

    stack<int> s5;
    s5.push(2);
    s5.push(0);
    cout << checkType(s5) << '\n';

    stack<int> s6;
    s6.push(1);
    s6.push(2);
    cout << checkType(s6) << '\n';

    StackNode *ll = new StackNode{s1, new StackNode{s2, new StackNode{s3, new StackNode{s4, new StackNode{s5, new StackNode{s6}}}}}};
    print(ll);

    assert(concatSimilarStackElems(ll) != nullptr);
    StackNode *concatenated = concatSimilarStackElems(ll);
    print(concatenated);

    free(ll);
    return 0;
}