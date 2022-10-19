#include <iostream>
#include <stack>
#include <string>

std::string reverseWord(const std::string &str) {
    std::stack<char> s; // here we will save the letters
    // marto pi4a

    for (size_t i = 0; i < str.size(); i++) {
        s.push(str[i]); // pushing letter by letter the whole word
    }

    std::string reversed(str.size() + 1, '\0'); // create a string of size() + 1 and fill it with \0
    size_t i = 0;

    while (!s.empty()) {
        reversed[i++] = s.top();
        s.pop();
    }
    return reversed;
}

std::string reverseSubword(const std::string &str) {
    std::stack<char> s;
    std::string reversed(str.size() + 1, '\0');
    size_t iter = 0;

    for (size_t i = 0; i < str.size(); i++) {
        while (str[i] != ' ' && str[i] != '\0') {
            s.push(str[i]); // pushing the letters of a subword
            i++;
        }
        while (!s.empty()) { // empty the stack while saving the reversed subword
            reversed[iter++] = s.top();
            s.pop();
        }
        s.push(str[i]);             // pushing the blank space to the stack
        reversed[iter++] = s.top(); // adding the blank space to the reversed string
        s.pop();                    // now the stack is fully empty ready to save a new subword
    }
    return reversed;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    // std::cout << reverseWord(input);
    std::cout << reverseSubword(input);
}