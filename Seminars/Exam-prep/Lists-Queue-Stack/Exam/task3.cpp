#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool readAndDelete(stack<char> &s, const string &word) {
    unsigned int i = 0;
    stack<char> store;

    while (!s.empty()) {
        if (s.top() == word[i]) {
            i++;
            s.pop();
        } else {
            store.push(s.top());
            s.pop();
        }
    }

    while (!store.empty()) {
        s.push(store.top());
        store.pop();
    }

    return (i == word.size());
}

void print(stack<char> s) {
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << '\n';
}

void test1() {
    stack<char> stack;
    stack.push('m');
    stack.push('o');
    stack.push('o');
    stack.push('f');
    stack.push('m');
    string string = "mom";
    cout << readAndDelete(stack, string);
    print(stack);
}

void test2() {
    stack<char> stack;
    stack.push('y');
    stack.push('a');
    stack.push('d');
    stack.push('c');
    stack.push('c');
    string string = "car";
    cout << readAndDelete(stack, string);
    print(stack);
}

int main() {
    test1();
    test2();
}