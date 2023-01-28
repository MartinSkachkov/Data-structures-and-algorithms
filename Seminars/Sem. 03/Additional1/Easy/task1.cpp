#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int clock = q.size();

        if (clock > 1) {
            while (clock != 1) {
                int curr = q.front();
                q.pop();
                q.push(curr);
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