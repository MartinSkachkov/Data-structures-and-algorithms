#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
bool isBST(const Tree<T> *t, int min = INT_MIN, int max = INT_MAX) {
    if (t == nullptr) {
        return true;
    }

    if (t->data < min || t->data > max) {
        return false;
    }

    return isBST(t->left, min, t->data) && isBST(t->right, t->data, max);
}

template <typename T>
int min_elem(const Tree<T> *t) {
    while (t != nullptr && t->left != nullptr) {
        t = t->left;
    }
    return t->data;
}

template <typename T>
int max_elem(const Tree<T> *t) {
    while (t != nullptr && t->right != nullptr) {
        t = t->right;
    }
    return t->data;
}

int main() {
    Tree<int> *tree = new Tree<int>(15, new Tree<int>(10, new Tree<int>(9, new Tree<int>(8, new Tree<int>(7))), new Tree<int>(12)), new Tree<int>(19));

    printTree(tree);
    cout << "Bst? " << isBST(tree) << '\n';
    cout << "Min elem: " << min_elem(tree) << '\n';
    cout << "Max elem: " << max_elem(tree) << '\n';

    freeTree(tree);
    return 0;
}