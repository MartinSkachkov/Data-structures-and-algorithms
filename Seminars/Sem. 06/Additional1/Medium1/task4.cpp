#include "tree-utils.h"

template <typename T>
int treeHeight(Tree<T> *t) {
    // empty tree has a height of zero
    if (t == nullptr) {
        return 0;
    }

    // single node or a leaf node also has a height of zero
    if (t->left == nullptr && t->right == nullptr) {
        return 0;
    }

    int leftH = treeHeight(t->left) + 1;
    int rightH = treeHeight(t->right) + 1;

    return max(leftH, rightH);
}

template <typename T>
int diameter(Tree<T> *t) {
    // if the tree is empty or we have a single root node
    if (t == nullptr || (t->left == nullptr && t->right == nullptr)) {
        return 0;
    }

    return treeHeight(t->left) + treeHeight(t->right) + 2; // +2 for the two edges between the main root and l&r subtrees
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));
    Tree<int> *t2 = new Tree<int>(2, new Tree<int>(3, new Tree<int>(5, nullptr, new Tree<int>(8, nullptr, new Tree<int>(6, new Tree<int>(7, nullptr, new Tree<int>(15)), nullptr))), nullptr), new Tree<int>(3, nullptr, new Tree<int>(7)));

    printTree(t);
    cout << "Diameter: " << diameter(t) << '\n';

    printTree(t2);
    cout << "Diameter: " << diameter(t2) << '\n';

    freeTree(t);
    freeTree(t2);
    return 0;
}