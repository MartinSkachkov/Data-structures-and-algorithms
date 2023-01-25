#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseWordOrder(const string &str) {
    stack<string> s;
    string subword;
    string reversed;

    // "Technical Interview Preparation"
    for (size_t i = 0; i < str.size(); i++) {

        if (i == str.size() - 1) {
            subword += str[i]; // Preparation
            s.push(subword);
            subword.clear();
            continue;
        } else if (str[i] == ' ') {
            s.push(subword);
            subword.clear();
            continue;
        }
        subword += str[i];
    }

    while (!s.empty()) {
        reversed += s.top() + ' ';
        s.pop();
    }

    return reversed;
}

int main() {
    string s = "Technical Interview Preparation";
    cout << reverseWordOrder(s);

    return 0;
}