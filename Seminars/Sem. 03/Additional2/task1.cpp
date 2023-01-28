#include <iostream>
#include <queue>
using namespace std;

// S:
// 3
// 2
// 1

class MyStack {
private:
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int clock = q.size();

        // we are poping & pushing till reverse
        if (clock > 1) {
            while (clock != 1) {
                int elem = q.front();
                q.pop();
                q.push(elem);
                clock--;
            }
        }
    }

    int pop() {
        if (empty()) {
            throw "Can't pop in empty queue!";
        }
        int front = q.front();
        q.pop();
        return front;
    }

    int top() {
        if (empty()) {
            throw "Can't top in empty queue!";
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack *myStack = new MyStack();
    myStack->push(1);
    myStack->push(2);
    cout << myStack->top();   // return 2
    cout << myStack->pop();   // return 2
    cout << myStack->empty(); // return False

    return 0;
}