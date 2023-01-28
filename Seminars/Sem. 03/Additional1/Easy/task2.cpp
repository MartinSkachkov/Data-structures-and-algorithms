#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
    int front;

public:
    void push(int x) {
        if (s1.empty()) {
            front = x;
        }
        q.push(x);
    }

    void pop() {
        if (s2.empty()) { // s2 looks like a queue
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int peek() {
        if (!s2.empty()) {
            s2.top();
        }
        return front;
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};