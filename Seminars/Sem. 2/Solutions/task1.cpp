#include <iostream>
#include <stack>
#include <string>

std::string erase(const std::string &str) {
    std::stack<char> s;

    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '*') {
            if (s.empty()) {
                throw "invalid expr";
            }
            s.pop();
        } else {
            s.push(str[i]);
        }
    }
    std::string res(s.size() + 1, '\0');
    size_t indx = s.size() - 1;

    while (!s.empty()) {
        res[indx--] = s.top();
        s.pop();
    }
    return res;
}

int main() {
    std::string str;
    // cin>>str; will only contain the part of string till first space
    getline(std::cin, str); // read white spaces
    std::cout << erase(str);

    return 0;
}