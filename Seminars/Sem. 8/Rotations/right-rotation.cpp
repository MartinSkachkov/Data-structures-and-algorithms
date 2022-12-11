#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
void right_rotation(Tree<T> *&tree) {
    assert(tree != nullptr && tree->left != nullptr);

    Tree<T> *tmp = tree;
    tree = tree->left;
    tmp->left = tree->right;
    tree->right = tmp;
}

int main() {
    Tree<int> *tree = new Tree<int>(15, new Tree<int>(10, new Tree<int>(9, new Tree<int>(8, new Tree<int>(7))), new Tree<int>(12)), new Tree<int>(19));

    printTree(tree);
    right_rotation(tree);
    printTree(tree);

    freeTree(tree);
    return 0;
}