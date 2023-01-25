#include <iostream>
#include <stack>
using namespace std;

bool validBrackets(const string &str) {
    stack<char> s;

    // "()[]{}"
    // "(]"
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        } else if ((str[i] == ')' && s.top() == '(') || (str[i] == ']' && s.top() == '[') || (str[i] == '}' && s.top() == '{')) {
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
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "{[]}";

    cout << validBrackets(s1);
    cout << validBrackets(s2);
    cout << validBrackets(s3);
    cout << validBrackets(s4);
    cout << validBrackets(s5);

    return 0;
}