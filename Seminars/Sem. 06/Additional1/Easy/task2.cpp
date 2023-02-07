#include "tree-utils.h"

// the height is the max number of edges from the root to some leaf
int treeHeight(Tree<int> *t) {
    // if we have an empty tree return 0
    if (t == nullptr) {
        return 0;
    }

    // if we have a single node or we reached a leaf
    if (t->left == nullptr && t->right == nullptr) {
        return 0;
    }

    // compute the height of the left & right subtree
    int leftH = treeHeight(t->left) + 1;
    int rightH = treeHeight(t->right) + 1;

    // pick the biggest height
    return max(leftH, rightH);
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, new Tree<int>(55, new Tree<int>(56, nullptr, new Tree<int>(56, new Tree<int>(56)))), new Tree<int>(69)))));

    printTree(t);
    cout << "Height: " << treeHeight(t);

    freeTree(t);
    return 0;
}