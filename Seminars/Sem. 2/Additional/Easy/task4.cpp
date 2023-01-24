#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string removeDuplicates(const string &str) {
    stack<char> s;

    for (size_t i = 0; i < str.size(); i++) {
        if (!s.empty() && str[i] == s.top()) {
            s.pop();
            continue;
        }
        s.push(str[i]);
    }

    string rev;
    while (!s.empty()) {
        rev.push_back(s.top());
        s.pop();
    }

    reverse(rev.begin(), rev.end());

    return rev;
}

int main() {
    string str;
    cin >> str;

    cout << removeDuplicates(str);

    return 0;
}