#include "tree-utils.h"

int leafNodes(Tree<int> *t) {
    // empty tree has zero leaf nodes
    if (t == nullptr) {
        return 0;
    }

    // condition for leaf node && single node
    if (t->left == nullptr && t->right == nullptr) {
        return 1;
    }

    int leftLN = 0, rightLN = 0; // at the beginning we don't know how many the leaf nodes will be

    leftLN += leafNodes(t->left);   // leaf nodes in the left subtree
    rightLN += leafNodes(t->right); // leaf nodes in the right subtree

    return rightLN + leftLN; // return all leaf nodes
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, new Tree<int>(20), new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));

    printTree(t);
    cout << "Leafs: " << leafNodes(t);

    freeTree(t);
    return 0;
}