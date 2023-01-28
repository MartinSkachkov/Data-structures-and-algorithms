#include <iostream>
#include <stack>

void printStack(std::stack<int> s) {
    if (s.empty()) { // base case of the recursion
        return;
    }

    int x = s.top();        // get the last element
    s.pop();                // pop the last element to reach the next one
    printStack(s);          // recursively get the second element
    std::cout << x << '\n'; // when finished print it
    s.push(x);              // push it again as you previously popped it
}

std::stack<int> sortStack(std::stack<int> &input) {
    std::stack<int> tmpStack;

    while (!input.empty()) {

        int tmp = input.top();
        input.pop();

        while (!tmpStack.empty() && tmpStack.top() > tmp) {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(tmp);
    }
    return tmpStack;
}

int main() {
    std::stack<int> input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);

    std::stack<int> tmpStack = sortStack(input);
    printStack(tmpStack);
    return 0;
}