#include "tree-utils.h"

int countNodes(Tree<int> *t) {
    // empty tree has zero nodes
    if (t == nullptr) {
        return 0;
    }

    int c = 1; // root node

    // traverse left
    if (t->left != nullptr) {
        c += countNodes(t->left);
    }
    // traverse right
    if (t->right != nullptr) {
        c += countNodes(t->right);
    }

    return c;
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));

    printTree(t);
    cout << "Nodes: " << countNodes(t);

    freeTree(t);
    return 0;
}
