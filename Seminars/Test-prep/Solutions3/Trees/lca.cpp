#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

// Function to check if a given node is present in a binary tree or not
template <typename T>
bool isNodePresent(const Tree<T> *t, const Tree<T> *elem) {
    // base case
    if (t == nullptr) {
        return false;
    }

    // if the node is found, return true
    if (t->data == elem->data) {
        return true;
    }

    // return true if a given node is found in the left or right subtree
    return isNodePresent(t->left, elem) || isNodePresent(t->right, elem);
}

// Function to find the lowest common ancestor of given nodes `x` and `y`, where
// both `x` and `y` are present in a binary tree.
// The function returns true if `x` or `y` is found in a subtree rooted at the root.
// `lca` —> stores `LCA(x, y)`, and it is passed by reference to the function
/*template <typename T>
bool process(Tree<T> *t, Tree<T> *&lca, Tree<T> *x, Tree<T> *y) {
    // base case 1: return false if the tree is empty
    if (t == nullptr) {
        return false;
    }

    // base case 2: return true if either `x` or `y` is found
    if (t == x || t == y) {
        // set lca to the current node
        lca = t;
        return true;
    }

    // recursively check if `x` or `y` exists in the left subtree
    bool left = process(t->left, lca, x, y);

    // recursively check if `x` or `y` exists in the right subtree
    bool right = process(t->right, lca, x, y);

    // if `x` is found in one subtree and `y` is found in the other subtree,
    // update lca to the current node
    if (left && right) {
        lca = t;
    }

    return left || right;
}

template <typename T>
void findLCA(Tree<T> *t, Tree<T> *x, Tree<T> *y) {
    // `lca` stores the lowest common ancestor
    Tree<T> *lca = nullptr;

    // call LCA procedure only if both `x` and `y` are present in the tree
    if (isNodePresent(t, x) && isNodePresent(t, y)) {
        process(t, lca, x, y);
    }

    // if LCA exists, print it
    if (lca == nullptr) {
        cout << "LCA not found!" << endl;
    } else {
        cout << "LCA: " << lca->data << endl;
    }
}*/

template <typename T>
const Tree<T> *find(const Tree<T> *t, const Tree<T> *x, const Tree<T> *y) {
    if (t == nullptr) {
        return nullptr;
    }

    if (t == x || t == y) {
        return t;
    }

    const Tree<T> *left = find(t->left, x, y);
    const Tree<T> *right = find(t->right, x, y);

    if (left && right) {
        return t;
    }

    if (left) {
        return left;
    }

    if (right) {
        return right;
    }
}

template <typename T>
void findLCA(const Tree<T> *t, const Tree<T> *x, const Tree<T> *y) {
    if (t == nullptr) {
        throw "Empty tree!";
    }

    const Tree<T> *lca = nullptr;

    if (isNodePresent(t, x) && isNodePresent(t, y)) {
        lca = find(t, x, y);
    }

    if (lca == nullptr) {
        cout << "Node is not found!" << endl;
    } else {
        cout << "LCA: " << lca->data << endl;
    }
}

int main() {
    /* Construct the following tree
          1
        /   \
       /     \
      2       3
       \     / \
        4   5   6
           / \
          7   8
    */

    Tree<int> *root = new Tree<int>(1);
    root->left = new Tree<int>(2);
    root->right = new Tree<int>(3);
    root->left->right = new Tree<int>(4);
    root->right->left = new Tree<int>(5);
    root->right->right = new Tree<int>(6);
    root->right->left->left = new Tree<int>(7);
    root->right->left->right = new Tree<int>(8);

    printTree(root);

    findLCA(root, root->right->left->left, root->right->right);
    findLCA(root, root->right->left->left, new Tree<int>(10));
    findLCA(root, root->right->left->left, root->right->left->left);
    findLCA(root, root->right->left->left, root->right->left);
    findLCA(root, root->left, root->right->left);

    freeTree(root);
    return 0;
}