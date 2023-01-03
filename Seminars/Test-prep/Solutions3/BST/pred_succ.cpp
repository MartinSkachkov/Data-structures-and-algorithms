#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
int findMaxEl(const Tree<T> *t) {
    if (t == nullptr) {
        return INT_MAX;
    }

    while (t->right != nullptr) {
        t = t->right;
    }

    return t->data;
}

template <typename T>
int findMinEl(const Tree<T> *t) {
    if (t == nullptr) {
        return INT_MIN;
    }

    while (t->left != nullptr) {
        t = t->left;
    }

    return t->data;
}

template <typename T>
int pred(const Tree<T> *t, const T &elem) {
    // no such element in the tree
    if (t == nullptr) {
        return INT_MIN;
    }

    if (elem < t->data) {
        pred(t->left, elem);
    } else if (elem > t->data) {
        pred(t->right, elem);
    } else {
        return findMaxEl(t->left);
    }
}

template <typename T>
int succ(const Tree<T> *t, const T &elem) {
    // no such element in the tree
    if (t == nullptr) {
        return INT_MAX;
    }

    if (elem < t->data) {
        succ(t->left, elem);
    } else if (elem > t->data) {
        succ(t->right, elem);
    } else {
        return findMinEl(t->right);
    }
}

int main() {
    Tree<int> *t = new Tree<int>(10, new Tree<int>(5, nullptr, new Tree<int>(8, new Tree<int>(6))), new Tree<int>(15, new Tree<int>(13, nullptr, new Tree<int>(14)), new Tree<int>(19, new Tree<int>(18), new Tree<int>(20))));

    printTree(t);
    cout << pred(t, 15) << endl;
    cout << succ(t, 15);

    freeTree(t);
    return 0;
}