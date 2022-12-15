#include "tree-utils.h"
#include <cassert>
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
bool search_elem(const Tree<T> *t, const T &elem) {
    if (t == nullptr) {
        return false;
    }

    if (t->data == elem) {
        return true;
    }

    // search left side
    if (elem < t->data) {
        return search_elem(t->left, elem);
    }
    // search right side
    if (elem > t->data) {
        return search_elem(t->right, elem);
    }
}

int main() {
    Tree<int> *tree = new Tree<int>(15, new Tree<int>(10, new Tree<int>(9, new Tree<int>(8, new Tree<int>(7))), new Tree<int>(12)), new Tree<int>(19));

    printTree(tree);
    cout << isBST(tree) << '\n';
    for (int i = 7; i < 20; i++) {
        cout << "elem: " << i << '-' << boolalpha << search_elem(tree, i) << '\n';
    }

    freeTree(tree);
    return 0;
}