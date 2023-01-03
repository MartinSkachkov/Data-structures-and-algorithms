#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
void leftRotation(Tree<T> *&t) {
    Tree<T> *tmp = t;
    t = t->right;
    tmp->right = t->left;
    t->left = tmp;
}

int main() {
    Tree<int> *t = new Tree<int>(10, new Tree<int>(8), new Tree<int>(15, new Tree<int>(13), new Tree<int>(16)));

    printTree(t);
    leftRotation(t);
    printTree(t);

    freeTree(t);
    return 0;
}