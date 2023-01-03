#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
Tree<T> *clone(const Tree<T> *t) {
    if (t == nullptr) {
        return nullptr;
    }

    return new Tree<T>(t->data, clone(t->left), clone(t->right));
}

int main() {
    Tree<int> *t = new Tree<int>(10, new Tree<int>(5, nullptr, new Tree<int>(8, new Tree<int>(6))), new Tree<int>(15, new Tree<int>(13, nullptr, new Tree<int>(14)), new Tree<int>(19, new Tree<int>(18), new Tree<int>(20))));

    Tree<int> *newTree = clone(t);
    cout << "original:\n";
    printTree(t);
    cout << "clone:\n";
    printTree(newTree);

    freeTree(newTree);
    freeTree(t);
    return 0;
}