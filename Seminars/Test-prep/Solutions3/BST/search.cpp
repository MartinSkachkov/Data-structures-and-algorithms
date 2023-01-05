#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
Tree<T> *search(Tree<T> *t, const T &node) {
    if (t == nullptr) {
        return nullptr;
    }

    if (node < t->data) {
        search(t->left, node);
    }
    if (node > t->data) {
        search(t->right, node);
    } else {
        return t;
    }
}

int main() {
    Tree<int> *t = new Tree<int>(10, new Tree<int>(5, nullptr, new Tree<int>(8, new Tree<int>(6))), new Tree<int>(15, new Tree<int>(13, nullptr, new Tree<int>(14)), new Tree<int>(19, new Tree<int>(18), new Tree<int>(20))));

    printTree(t);
    Tree<int> *newRoot = search(t, 19);
    assert(newRoot != nullptr);
    printTree(newRoot);

    freeTree(t);
    return 0;
}