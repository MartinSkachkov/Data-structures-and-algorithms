#include "tree-utils.h"
#include <stack>

bool isOperation(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

Tree<char> *buildExprTree(const string &postfixExpr) {
    // if the length of the string is zero then the tree will be empty
    if (postfixExpr.length() == 0) {
        return nullptr;
    }

    stack<Tree<char> *> s; // here we will save the created nodes

    // iterate over the string
    for (size_t i = 0; i < postfixExpr.size(); i++) {

        if (isOperation(postfixExpr[i])) { // it needs to be a root of the current tree

            Tree<char> *leftSub = s.top();
            s.pop();

            Tree<char> *rightSub = s.top();
            s.pop();

            // link the r&l subtrees to the new root
            Tree<char> *root = new Tree<char>(postfixExpr[i], leftSub, rightSub);
            s.push(root);

        } else {                                    // it is an operand so just push it
            s.push(new Tree<char>(postfixExpr[i])); // |/|val|/|
        }
    }
    return s.top();
}

int main() {
    string expr = "23-52*/1+";
    Tree<char> *t = buildExprTree(expr);
    printTree(t);

    freeTree(t);
    return 0;
}
