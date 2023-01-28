#include <iostream>
#include <stack>
#include <string>

bool isOperation(const char &c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

bool isDigit(const char &c) {
    return c >= '0' && c <= '9';
}

int convertCharToInt(const char &c) {
    return c - '0';
}

int eval(int first, int second, char operation) {
    switch (operation) {
    case '+':
        return first + second;
    case '-':
        return first - second;
    case '*':
        return first * second;
    case '/':
        return first / second;
    default:
        std::cerr << "Invalid operation";
    }
}

int reversedPolishNotation(const std::string &str) {
    std::stack<int> s;

    for (size_t i = 0; i < str.size(); i++) {
        if (isOperation(str[i])) {
            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();

            s.push(eval(first, second, str[i]));
        } else if (str[i] != ' ') {
            int number = 0;
            while (i < str.size() && isDigit(str[i])) {
                number *= 10;
                number += convertCharToInt(str[i]);
                i++;
            }

            i--;
            s.push(number);
        }
    }
    return s.top();
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << str;
    std::cout << reversedPolishNotation(str); //"9 3 4 * - 2 5 * -"

    return 0;
}