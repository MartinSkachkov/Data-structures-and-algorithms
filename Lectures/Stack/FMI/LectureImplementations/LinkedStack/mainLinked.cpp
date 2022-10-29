#include "LinkedStack.hpp"
#include <vector>

int main() {
    LinkedStack<int> s;
    std::vector<LinkedStack<int>> vec;
    vec.push_back(LinkedStack<int>()); // calling move constructor

    s = LinkedStack<int>(); // calling move op=

    return 0;
}