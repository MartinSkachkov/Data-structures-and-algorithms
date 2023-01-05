#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
void printChildren(const Tree<T> *t) {
    if (t == nullptr) {
        return;
    }

    if (t->left == nullptr && t->right == nullptr) {
        cout << t->data;
    }

    printChildren(t->left);
    printChildren(t->right);
}

int main() {
    Tree<int> *t = new Tree<int>(2, new Tree<int>(43), new Tree<int>(13, new Tree<int>(7), new Tree<int>(8)));

    printTree(t);
    printChildren(t);

    freeTree(t);
    return 0;
}