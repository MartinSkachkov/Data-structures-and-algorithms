#include <iostream>
#include <stack>

void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << '\n';
        s.pop();
    }
}

std::stack<int> bottomInsertion(std::stack<int> s, int num) {
    std::stack<int> helpStack;

    while (!s.empty()) {
        helpStack.push(s.top());
        s.pop();
    }
    s.push(num);

    while (!helpStack.empty()) {
        s.push(helpStack.top());
        helpStack.pop();
    }
    return s;
}

int main() {
    std::stack<int> s;
    for (size_t i = 0; i < 3; i++) {
        s.push(i);
    }

    std::stack<int> result = bottomInsertion(s, 5);
    printStack(result);
    return 0;
}