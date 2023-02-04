#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
bool contains(const Tree<T> *tree, const T &elem) {
    bool res = tree->data == elem;

    if (tree->left != nullptr && !res) {
        res = contains(tree->left, elem);
    }
    if (tree->right != nullptr && !res) {
        res = contains(tree->right, elem);
    }

    return res;
}

int main() {
    Tree<int> *root = new Tree<int>(2, new Tree<int>(3), new Tree<int>(13, new Tree<int>(7), new Tree<int>(8)));

    cout << "Contains: " << boolalpha << contains(root, 7) << '\n';
    cout << "Contains: " << boolalpha << contains(root, 69) << '\n';
    printTree(root);

    freeTree(root);
    return 0;
}