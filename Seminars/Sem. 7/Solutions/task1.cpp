#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
void insertBST(Tree<T> *&t, const T &elem) {
    if (t == nullptr) {
        t = new Tree<T>(elem);
        return;
    }

    if (t->data < elem) {
        insertBST(t->right, elem);
    }
    if (t->data > elem) {
        insertBST(t->left, elem);
    }
}

int main() {
    Tree<int> *example = new Tree<int>(4, new Tree<int>(2), new Tree<int>(6));
    printTree(example);
    insertBST(example, 1);
    printTree(example);

    freeTree(example);
    return 0;
}