#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
int tree_hight(const Tree<T> *tree) {
    int h = 0;

    if (tree->left != nullptr) {
        h = 1 + tree_hight(tree->left);
    }
    if (tree->right != nullptr) {
        h = max(h, 1 + tree_hight(tree->right));
    }

    return h;
}

int main() {
    Tree<int> *root = new Tree<int>(8, new Tree<int>(3, new Tree<int>(1), new Tree<int>(6, new Tree<int>(4), new Tree<int>(7))), new Tree<int>(10, nullptr, new Tree<int>(14, new Tree<int>(13, nullptr, new Tree<int>(1)))));

    printTree(root);
    cout << '\n'
         << "Height: " << tree_hight(root) << '\n';

    freeTree(root);
    return 0;
}
