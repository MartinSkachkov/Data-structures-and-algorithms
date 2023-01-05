#include "tree-utils.h"
#include <cassert>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int getPrio(char c) {
    switch (c) {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;

    default:
        break;
    }
    throw "Invalid operation\n";
}

template <typename T>
void combine(stack<char> &ops, stack<Tree<T> *> &s) {
    Tree<T> *root = new Tree<T>(ops.top());
    ops.pop();

    root->right = s.top();
    s.pop();
    root->left = s.top();
    s.pop();

    s.push(root);
}

template <typename T = char>
Tree<T> *expTree(const string &expr) {
    stack<char> ops;
    stack<Tree<T> *> s;

    for (size_t i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == '(') {
            ops.push(ch);
        } else if (isdigit(ch)) {
            s.push(new Tree<T>(ch));
        } else if (ch == ')') {
            while (ops.top() != '(') {
                combine(ops, s);
            }
            ops.pop();
        } else {
            while (!ops.empty() && getPrio(ops.top()) >= getPrio(ch)) {
                combine(ops, s);
            }
            ops.push(ch);
        }
    }

    while (s.size() > 1) {
        combine(ops, s);
    }
    return s.top();
}

int main() {
    string expr = "2-3/(5*2)+1";
    Tree<char> *t = expTree(expr);
    printTree(t);

    freeTree(t);
    return 0;
}