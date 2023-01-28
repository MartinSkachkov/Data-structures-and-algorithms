#include <iostream>
#include <stack>
using namespace std;

// q: 1,2,3,4

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
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res = s2.top();
        s2.pop();
        return res;
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

int main() {
    MyQueue *myQueue = new MyQueue();
    myQueue->push(1);         // queue is: [1]
    myQueue->push(2);         // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue->peek();  // return 1
    cout << myQueue->pop();   // return 1, queue is [2]
    cout << myQueue->empty(); // return false

    return 0;
}