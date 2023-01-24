#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool valid_parentheses(const string &str) {
    stack<char> s;

    // (()())
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        } else if (s.empty()) { // )()
            return false;
        } else if (((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[') || (str[i] == '}' && s.top() == '{'))) {
            s.pop();
        } else {
            return false;
        }
    }

    if (s.empty()) {
        return true;
    }

    return false;
}

int main() {
    vector<string> vParentheses = {"()",
                                   "()()",
                                   "(()())",
                                   "{}{}",
                                   "(((())))",
                                   "([])",
                                   "()[]{}",
                                   "{[]}"};
    for (string p : vParentheses) {
        cout << valid_parentheses(p) << '\n';
    }
    cout << '\n';
    vector<string> iParentheses = {
        "(]",
        "())",
        "(][)",
        "(]",
        "([)]"};
    for (string p : iParentheses) {
        cout << valid_parentheses(p) << '\n';
    }

    return 0;
}