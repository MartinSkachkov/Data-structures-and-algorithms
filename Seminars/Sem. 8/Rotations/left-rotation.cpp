#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
void left_rotation(Tree<T> *&tree) {
    assert(tree != nullptr && tree->right != nullptr);

    Tree<T> *tmp = tree;
    tree = tree->right;
    tmp->right = tree->left;
    tree->left = tmp;
}

int main() {
    Tree<int> *tree = new Tree<int>(1, nullptr, new Tree<int>(3, nullptr, new Tree<int>(6, new Tree<int>(4), new Tree<int>(8, new Tree<int>(7), new Tree<int>(9)))));

    printTree(tree);
    left_rotation(tree);
    left_rotation(tree);
    printTree(tree);

    freeTree(tree);
    return 0;
}