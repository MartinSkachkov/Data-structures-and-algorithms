#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
bool exists(const Tree<T> *t, const T &elem) {
    if (t->data == elem) {
        return true;
    }

    if (elem < t->data) {
        return t->left != nullptr && exists(t->left, elem);
    }

    if (elem > t->data) {
        return t->right != nullptr && exists(t->right, elem);
    }
}

int main() {
    Tree<int> *root = new Tree<int>(2, new Tree<int>(3), new Tree<int>(13, new Tree<int>(7), new Tree<int>(8)));
    printTree(root);
    cout << endl
         << "Exists: " << exists(root, 7) << '\n'
         << "Exists: " << exists(root, 69);
    freeTree(root);
    return 0;
}