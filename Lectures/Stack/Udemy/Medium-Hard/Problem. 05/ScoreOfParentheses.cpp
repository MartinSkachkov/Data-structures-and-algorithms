#include <iostream>
#include <stack>
#include <string>

int scoreOfParentheses(std::string str) {
    std::stack<char> s;
    int score = 0;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            s.push('(');
        } else if (s.empty() && str[i] == ')') {
            return -1;
        }

        char topParentheses = s.top();
        if (str[i] == ')' && topParentheses == '(') {
            s.pop();
            score++;
        }
    }

    if (s.empty()) {
        return score;
    }
    return -1;
}

int main() {
    std::string str;
    getline(std::cin, str);
    std::cout << scoreOfParentheses(str);
    return 0;
}