#include "RStack.hpp"
#include <vector>

int main() {
    RStack<int> s;
    std::vector<RStack<int>> vec;
    vec.push_back(RStack<int>()); // calling move constructor

    s = RStack<int>(); // calling move op=
    return 0;
}