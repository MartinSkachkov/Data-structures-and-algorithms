#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string &str) {
    // deleting one bracket
    //((()
    std::stack<char> s;
    bool removedBracket = false;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ')') {
            if (s.empty()) {
                if (!removedBracket) {
                    removedBracket = true;
                } else {
                    return false;
                }
            } else {
                s.pop(); //(,(
            }
        } else {
            s.push(str[i]); //(,(,(
        }
    }

    if (!(s.empty() || removedBracket)) {
        s.pop(); // pop ( -> (
    }
    return s.empty();
}

int main() {
    std::cout << std::boolalpha << isBalanced("((())");
    return 0;
}