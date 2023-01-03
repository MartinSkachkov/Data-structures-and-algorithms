#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
bool isBst(const Tree<T> *t, int min = INT_MIN, int max = INT_MAX) {
    // base case
    if (t == nullptr) {
        return true;
    }

    // conditions in which our tree is not BST
    if (t->data < min || t->data > max) {
        return false;
    }

    return isBst(t->left, min, t->data) && isBst(t->right, t->data, max);
}

int main() {
    Tree<int> *example = new Tree<int>(4, new Tree<int>(2), new Tree<int>(6));
    Tree<int> *example2 = new Tree<int>(4, new Tree<int>(8), new Tree<int>(6));

    cout << isBst(example) << endl;
    cout << isBst(example2) << endl;

    freeTree(example);
    freeTree(example2);
    return 0;
}