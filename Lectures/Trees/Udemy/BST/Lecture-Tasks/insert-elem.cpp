#include "tree-utils.h"
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
void insert_elem(Tree<T> *&t, const T &elem) {
    if (t == nullptr) {
        t = new Tree<T>(elem);
        return;
    }

    if (elem < t->data) {
        insert_elem(t->left, elem);
    }
    if (elem > t->data) {
        insert_elem(t->right, elem);
    }
}
int main() {
    Tree<int> *tree = new Tree<int>(15, new Tree<int>(10, new Tree<int>(9, new Tree<int>(8, new Tree<int>(7))), new Tree<int>(12)), new Tree<int>(19));

    printTree(tree);
    cout << isBST(tree) << '\n';

    insert_elem(tree, 64);
    printTree(tree);
    cout << isBST(tree) << '\n';

    insert_elem(tree, -3);
    printTree(tree);
    cout << isBST(tree) << '\n';

    freeTree(tree);
    return 0;
}