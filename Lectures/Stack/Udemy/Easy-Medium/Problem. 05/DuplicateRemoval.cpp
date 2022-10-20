#include <iostream>
#include <stack>
#include <string>

std::string duplicateRemoval(const std::string &str) {
    std::stack<char> s;

    for (size_t i = 0; i < str.size(); i++) {
        if (!s.empty() && str[i] == s.top()) {
            s.pop();
        } else {
            s.push(str[i]);
        }
    }

    std::string res(s.size(), '\0'); // creates a string with <size>, <values>
    size_t indx = s.size() - 1;

    while (!s.empty()) {
        res[indx--] = s.top();
        s.pop();
    }
    return res;
}

int main() {
    std::string str;
    getline(std::cin, str);
    std::stack<char> s;
    for (size_t i = 0; i < str.size(); i++) {
        s.push(str[i]);
    }
    std::cout << s.top();

    // std::cout << duplicateRemoval(str);

    return 0;
}