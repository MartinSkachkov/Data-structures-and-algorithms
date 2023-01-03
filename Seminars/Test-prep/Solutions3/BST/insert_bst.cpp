#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
void insert(Tree<T> *&t, const T &elem) {
    if (t == nullptr) {
        t = new Tree<T>(elem);
        return;
    }

    if (t->data < elem) {
        insert(t->left, elem);
    }

    if (t->data > elem) {
        insert(t->right, elem);
    }
}

int main() {
    Tree<int> *example = new Tree<int>(4, new Tree<int>(2), new Tree<int>(6));

    insert(example, 1);
    printTree(example);

    freeTree(example);
    return 0;
}