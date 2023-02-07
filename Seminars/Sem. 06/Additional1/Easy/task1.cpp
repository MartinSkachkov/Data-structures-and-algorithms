#include "tree-utils.h"

int maxNode(Tree<int> *t) {
    // empty tree , return the smallest possible value
    if (t == nullptr) {
        return INT_MIN;
    }

    // save the current value
    int maxN = t->data;

    // traverse left
    if (t->left != nullptr) {
        maxN = max(maxN, maxNode(t->left));
    }
    // traverse right
    if (t->right != nullptr) {
        maxN = max(maxN, maxNode(t->right));
    }

    return maxN;
}

int minNode(Tree<int> *t) {
    // empty tree, return the maximum possible value
    if (t == nullptr) {
        return INT_MAX;
    }

    // save the current value
    int minN = t->data;

    // traverse left subtree
    if (t->left != nullptr) {
        minN = min(minN, minNode(t->left));
    }
    // traverse right subtree
    if (t->right != nullptr) {
        minN = min(minN, minNode(t->right));
    }

    return minN;
}

int main() {
    Tree<int> *t = new Tree<int>(2, new Tree<int>(43), new Tree<int>(13, new Tree<int>(7), new Tree<int>(8)));

    printTree(t);
    cout << "Max: " << maxNode(t) << '\n';
    cout << "Min: " << minNode(t) << '\n';

    freeTree(t);
    return 0;
}