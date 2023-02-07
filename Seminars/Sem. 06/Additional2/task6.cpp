#include "tree-utils.h"
#include <stack>

string convertToPostfix(string) {
    // to do
}

bool isOperation(char c) {
    return c == '+' || c == '-' || c == '/' || c == '*';
}

Tree<char> *buildExprTree(string postfixExpr) {
    // if the string is empty then return nullptr
    if (postfixExpr.size() == 0) {
        return nullptr;
    }

    // create an empty stack where we will save the nodes
    stack<Tree<char> *> s;

    // iterate over the string
    for (char c : postfixExpr) {
        if (isOperation(c)) {
            Tree<char> *leftSub = s.top(); // get the pointer to the left subtree root
            s.pop();

            Tree<char> *rightSub = s.top(); // get the pointer to the right subtree root
            s.pop();

            // construct a new binary tree whose root is the operator and whose
            // left and right children point to `leftSub` and `rightSub`, respectively
            Tree<char> *newRoot = new Tree<char>(c, leftSub, rightSub);

            s.push(newRoot);
        } else {
            // if the current char is not an operation just add it to the stack
            s.push(new Tree<char>(c));
        }
    }
    // a pointer to the root of the expression tree remains on the stack
    return s.top();
}

int main() {
    string expr = "23-52*/1+";
    Tree<char> *t = buildExprTree(expr);
    printTree(t);

    freeTree(t);
    return 0;
}