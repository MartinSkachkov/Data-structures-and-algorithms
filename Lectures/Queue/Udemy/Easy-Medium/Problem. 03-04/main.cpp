#include "QueueUsing2Stacks.hpp"
#include <iostream>

int main() {
    MyQueue<int> qu;

    for (int i = 1; i <= 3; ++i)
        qu.push(i);

    std::cout << qu.front() << " ";
    qu.pop();

    for (int i = 4; i <= 5; ++i)
        qu.push(i);

    while (!qu.empty()) {
        std::cout << qu.front() << " ";
        qu.pop();
    }
    return 0;
}