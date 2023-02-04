#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
void rotate_left(Tree<T> *&t) {
    assert(t != nullptr && t->right != nullptr);

    Tree<T> *tmp = t;
    t = t->right;
    tmp->right = t->left;
    t->left = tmp;
}

template <typename T>
void rotate_right(Tree<T> *&t) {
    assert(t != nullptr && t->left != nullptr);

    Tree<T> *tmp = t;
    t = t->left;
    tmp->left = t->right;
    t->right = tmp;
}

int main() {
    Tree<int> *tree = new Tree<int>(1, nullptr, new Tree<int>(3, nullptr, new Tree<int>(6, new Tree<int>(4), new Tree<int>(8, new Tree<int>(7), new Tree<int>(9)))));

    printTree(tree);
    rotate_left(tree);
    rotate_left(tree);
    printTree(tree);

    freeTree(tree);

    ///////////////////////////////////////////////////

    Tree<int> *tree2 = new Tree<int>(15, new Tree<int>(10, new Tree<int>(9, new Tree<int>(8, new Tree<int>(7))), new Tree<int>(12)), new Tree<int>(19));

    printTree(tree2);
    rotate_right(tree2);
    printTree(tree2);

    freeTree(tree2);
    return 0;
}