#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
bool isNodePresent(const Tree<T> *t, const Tree<T> *elem) {
    if (t == nullptr) {
        return false;
    }

    if (t->data == elem->data) {
        return true;
    }

    return isNodePresent(t->left, elem) || isNodePresent(t->right, elem);
}

template <typename T>
int find(const Tree<T> *root, const T &t, int l) {
    if (root == nullptr)
        return 0;
    if (root->data == t)
        return l;
    int x = find(root->left, t, l + 1);
    if (x != 0)
        return x;
    x = find(root->right, t, l + 1);
    return x;
}

template <typename T>
int getLevel(const Tree<T> *t, const T &target) {
    if (t == nullptr) {
        return 0;
    }
    int l = 1; // if we want the edges then l = 0 (and remove -1 from the return of findDistance)
    return find(t, target, l);
}

// Function to find the lowest common ancestor of given nodes `x` and `y`,
// where both `x` and `y` are present in a binary tree.
template <typename T>
const Tree<T> *findLCA(const Tree<T> *t, const Tree<T> *x, const Tree<T> *y) {
    if (t == nullptr) {
        return nullptr;
    }

    if (t == x || t == y) {
        return t;
    }

    const Tree<T> *left = findLCA(t->left, x, y);
    const Tree<T> *right = findLCA(t->right, x, y);

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

// Function to find the distance between node `x` and node `y` in a
// given binary tree rooted at `root` node
template <typename T>
int findDistance(const Tree<T> *t, const Tree<T> *x, const Tree<T> *y) {
    if (t == nullptr) {
        return INT_MIN;
    }

    const Tree<T> *lca = nullptr;

    if (isNodePresent(t, x) || isNodePresent(t, y)) {
        lca = findLCA(t, x, y);
    } else {
        return INT_MIN;
    }

    return getLevel(lca, x->data) + getLevel(lca, y->data) - 1;
}

int main() {
    /* Construct the following tree
            1
          /   \
         /     \
        2       3
         \     / \
          4   5   6
             /     \
            7       8
      */

    Tree<int> *root = new Tree<int>(1);
    root->left = new Tree<int>(2);
    root->right = new Tree<int>(3);
    root->left->right = new Tree<int>(4);
    root->right->left = new Tree<int>(5);
    root->right->right = new Tree<int>(6);
    root->right->left->left = new Tree<int>(7);
    root->right->right->right = new Tree<int>(8);

    // find the distance between node 7 and node 6
    cout << findDistance(root, root->right->left->left, root->right->right);

    return 0;
}