#include "tree-utils.h"

bool isOperation(string c) {
    return c == "+" || c == "-" || c == "*" || c == "/";
}

template <typename T>
void inorder(Tree<T> *root) {
    if (root == nullptr) {
        return;
    }

    // if the current token is an operator, print open parenthesis
    if (isOperation(root->data)) {
        cout << "(";
    }

    inorder(root->left);
    cout << root->data;
    inorder(root->right);

    // if the current token is an operator, print close parenthesis
    if (isOperation(root->data)) {
        cout << ")";
    }
}

int main() {
    Tree<string> *t = new Tree<string>("*", new Tree<string>("+", new Tree<string>("4"), new Tree<string>("5")), new Tree<string>("3"));

    printTree(t);
    inorder(t);

    freeTree(t);
    return 0;
}