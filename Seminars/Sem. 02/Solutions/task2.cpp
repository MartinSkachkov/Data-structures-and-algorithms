#include <iostream>
#include <stack>
#include <string>

bool brackets(const std::string &str) {
    std::stack<char> s;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == ')') {
            if (s.empty()) { // case when we have more closing than opening
                return false;
            }
            s.pop();
        } else if (str[i] == '(') {
            s.push(str[i]);
        }
    }

    /*if (!s.empty()) { // case when we have more opening than closing
         return false;
     } else {
         return true;
     }*/
    return s.empty();
}

bool diffBrackets(const std::string &str) {
    std::stack<char> s;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
            s.push(str[i]);
        } else {
            if (s.empty()) {
                return false;
            }
        }

        char topEl = s.top();
        if ((str[i] == ')' && topEl == '(') || (str[i] == '}' && topEl == '{') || (str[i] == ']' && topEl == '[')) {
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    // std::string str;
    // getline(std::cin, str);
    // std::cout << std::boolalpha << brackets(str);
    std::cout << std::boolalpha << diffBrackets("({)[]}}}");

    return 0;
}