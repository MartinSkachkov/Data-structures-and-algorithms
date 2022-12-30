#include "tree-utils.h"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
int eval(Tree<T> *root) {
    // empty tree
    if (!root)
        return 0;

    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return stoi(root->data);

    // Evaluate left subtree
    int l_val = eval(root->left);

    // Evaluate right subtree
    int r_val = eval(root->right);

    // Check which operator to apply
    if (root->data == "+")
        return l_val + r_val;
    else if (root->data == "-")
        return l_val - r_val;
    else if (root->data == "*")
        return l_val * r_val;
    else
        return l_val / r_val;
}

int main() {
    Tree<string> *t = new Tree<string>("+", new Tree<string>("*", new Tree<string>("5"), new Tree<string>("4")), new Tree<string>("-", new Tree<string>("100"), new Tree<string>("/", new Tree<string>("20"), new Tree<string>("2"))));

    printTree(t);

    assert(t != nullptr);
    cout << "Result: " << eval(t);

    freeTree(t);
    return 0;
}