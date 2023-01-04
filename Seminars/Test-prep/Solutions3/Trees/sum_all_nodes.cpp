#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
int sumAllElems(const Tree<T> *t) {
    int res = t->data;

    if (t->left != nullptr) {
        res += sumAllElems(t->left);
    }

    if (t->right != nullptr) {
        res += sumAllElems(t->right);
    }

    return res;
}

int main() {
    Tree<int> *t = new Tree<int>(10, new Tree<int>(5, nullptr, new Tree<int>(8, new Tree<int>(6))), new Tree<int>(15, new Tree<int>(13, nullptr, new Tree<int>(14)), new Tree<int>(19, new Tree<int>(18), new Tree<int>(20))));

    printTree(t);
    cout << "Sum: " << sumAllElems(t);

    freeTree(t);
    return 0;
}