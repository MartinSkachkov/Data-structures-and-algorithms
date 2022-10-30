#include "StackUsingQueue.hpp"
#include <iostream>

int main() {
    MyStack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);

    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    } // 30 20 10

    return 0;
}