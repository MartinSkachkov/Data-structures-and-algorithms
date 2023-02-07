#include "tree-utils.h"
#include <cmath>

int countNodes(Tree<int> *t) {
    // empty tree has zero nodes
    if (t == nullptr) {
        return 0;
    }

    int c = 1; // root node

    c += countNodes(t->left);  // traverse left;
    c += countNodes(t->right); // traverse right

    return c;
}

int treeHeight(Tree<int> *t) {
    // empty tree has height 0
    if (t == nullptr) {
        return 0;
    }

    // single node or leaf nodes also has hight zero
    if (t->left == nullptr && t->right == nullptr) {
        return 0;
    }

    int leftH = treeHeight(t->left) + 1;
    int rightH = treeHeight(t->right) + 1;

    return max(leftH, rightH);
}

bool isPerfect(Tree<int> *t) {
    return pow(2, treeHeight(t) + 1) - 1 == countNodes(t);
}

int main() {
    Tree<int> *t = new Tree<int>(2, new Tree<int>(3, new Tree<int>(5), new Tree<int>(6)), new Tree<int>(13, new Tree<int>(7), new Tree<int>(8)));
    Tree<int> *t2 = new Tree<int>(2, new Tree<int>(3, new Tree<int>(5, new Tree<int>(10)), new Tree<int>(6)), new Tree<int>(13, new Tree<int>(7), new Tree<int>(8)));

    printTree(t);
    cout << "Perfect? " << boolalpha << isPerfect(t);

    printTree(t2);
    cout << "Perfect? " << boolalpha << isPerfect(t2);

    freeTree(t);
    return 0;
}