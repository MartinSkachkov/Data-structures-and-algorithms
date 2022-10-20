#include <iostream>
#include <stack>
#include <string>

bool validBrackets(const std::string &str) {
    std::stack<char> s;

    // ({})
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            s.push(str[i]);
        } else {
            if (s.empty()) { // case when the first bracket in the string is closing
                return false;
            }
        }

        char currBracket = s.top();
        if ((str[i] == ')' && currBracket == '(') ||
            (str[i] == '}' && currBracket == '{') ||
            (str[i] == ']' && currBracket == '[')) {
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    std::string str;
    getline(std::cin, str);
    std::cout << std::boolalpha << validBrackets(str);

    return 0;
}