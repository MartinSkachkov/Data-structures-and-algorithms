#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
bool isBST(const Tree<T> *t, int min = INT_MIN, int max = INT_MAX) {
    if (t == nullptr) {
        return true;
    }

    if (t->data < min || t->data > max) {
        return false;
    }

    return isBST(t->left, min, t->data) && isBST(t->right, t->data, max);
}

template <typename T>
int min_elem(const Tree<T> *t) {
    while (t != nullptr && t->left != nullptr) {
        t = t->left;
    }
    return t->data;
}

template <typename T>
int inorder_succ(const Tree<T> *t, const T &elem, T succ = INT_MIN) {
    // base case
    if (t == nullptr) {
        return succ;
    }

    // if a node with the desired value is found, the successor is the minimum value
    // node in its right subtree (if any)
    if (t->data == elem) {
        if (t->right != nullptr) {
            return min_elem(t->right);
        }
    }
    // if the given key is less than the root node, recur for the left subtree
    if (elem < t->data) {
        succ = t->data; // save the parent data
        return inorder_succ(t->left, elem, succ);
    }

    // if the given key is greater than the root node, recur for the left subtree
    if (elem > t->data) {
        return inorder_succ(t->right, elem, succ);
    }
    return succ;
}

int main() {
    Tree<int> *tree = new Tree<int>(15, new Tree<int>(10, new Tree<int>(9, new Tree<int>(8, new Tree<int>(7))), new Tree<int>(12)), new Tree<int>(19));

    printTree(tree);
    cout << "Bst? " << isBST(tree) << '\n';
    for (int i = 7; i < 20; i++) {
        cout << inorder_succ(tree, i) << '\n';
    }

    freeTree(tree);
    return 0;
}