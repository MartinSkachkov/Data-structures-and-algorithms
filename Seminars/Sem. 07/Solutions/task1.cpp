#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
bool isBST(const Tree<T> *tree, int min, int max) {
    if (tree == nullptr) {
        return true;
    }

    // t->data < max && t->data > min to be a correct BST
    // so to be false BST this is the case:
    if (tree->data > max || tree->data < min) {
        return false;
    }

    return isBST(tree->left, min, tree->data) && isBST(tree->right, tree->data, max);
    //        (max) 8 (min)
    //             / \
    //     (curr) 5  10 (curr)
    //           /     \
    //    (min) 1       20 (max)
}

int main() {
    Tree<int> *tree = new Tree<int>(15, new Tree<int>(10, new Tree<int>(9, new Tree<int>(8, new Tree<int>(7))), new Tree<int>(12)), new Tree<int>(19));
    Tree<int> *tree2 = new Tree<int>(15, new Tree<int>(69, new Tree<int>(9, new Tree<int>(8, new Tree<int>(7))), new Tree<int>(12)), new Tree<int>(19));
    cout << boolalpha << "BST? " << isBST(tree, INT_MIN, INT_MAX) << '\n';
    cout << boolalpha << "BST? " << isBST(tree2, INT_MIN, INT_MAX) << '\n';

    freeTree(tree);
    freeTree(tree2);
    return 0;
}
