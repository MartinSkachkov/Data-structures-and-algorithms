#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

/*For example, when counting (()(())), our stack will look like this:

[0, 0] after parsing (
[0, 0, 0] after (
[0, 1] after )
[0, 1, 0] after (
[0, 1, 0, 0] after (
[0, 1, 1] after )
[0, 3] after )
[6] after ) */

int scoreOfParentheses(const string &str) {
    stack<int> s;
    s.push(0);

    for (char c : str) {
        if (c == '(') {
            s.push(0);
        } else {
            int top = s.top();
            s.pop();
            int below = s.top();
            s.pop();

            s.push(below + max(2 * top, 1));
        }
    }

    return s.top();
}

int main() {
    string str = "()((())())";
    cout << scoreOfParentheses(str);

    return 0;
}