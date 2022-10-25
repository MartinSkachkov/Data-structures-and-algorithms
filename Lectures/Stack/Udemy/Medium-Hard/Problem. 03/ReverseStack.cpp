#include <iostream>
#include <stack>

void printRecursively(std::stack<int> s) {
    if (s.empty()) { // base case of the recursion
        return;
    }

    int x = s.top();        // get the last element
    s.pop();                // pop the last element to reach the next one
    std::cout << x << '\n'; // print it the current top element
    printRecursively(s);    // recursively get the second element
    s.push(x);              // push it again as you previously popped it
}

void printStack(std::stack<int> s) {
    if (s.empty()) {
        return;
    }

    while (!s.empty()) {
        std::cout << s.top() << '\n';
        s.pop();
    }
}

std::stack<int> reverseStack(std::stack<int> s) {
    std::stack<int> reversed;
    while (!s.empty()) {
        reversed.push(s.top());
        s.pop();
    }
    return reversed;
}

int main() {
    std::stack<int> s;
    for (size_t i = 0; i < 3; i++) {
        s.push(i);
    }
    std::stack<int> reversed = reverseStack(s);
    printStack(reversed);
    printRecursively(reversed);
}