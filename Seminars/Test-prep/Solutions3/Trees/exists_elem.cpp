#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
bool exists_elem(Tree<T> *t, T elem) {
    int res = t->data == elem;

    if (t->left != nullptr) {
        res = res || exists_elem(t->left, elem);
    }

    if (t->right != nullptr) {
        res = res || exists_elem(t->right, elem);
    }

    return res;
}

template <typename T>
bool containsRec(const T &el, Tree<T> *t) {
    if (!t)
        return false;
    if (t->data == el)
        return true;

    if (el < t->data)
        return containsRec(el, t->left);
    else
        return containsRec(el, t->right);
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));
    Tree<int> *bst = new Tree<int>(10, new Tree<int>(8), new Tree<int>(15, new Tree<int>(13), new Tree<int>(16)));
    // assert(t != nullptr);
    // cout << "Exists: " << exists_elem(t, -6);
    // cout << "Exists: " << exists_elem(t, 69);

    printTree(bst);
    cout << containsRec(9, bst);

    freeTree(bst);
    freeTree(t);
    return 0;
}