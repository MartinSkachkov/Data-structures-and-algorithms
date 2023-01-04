#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
int find(const Tree<T> *t, const T &elem, int l) {
    if (t == nullptr) {
        return 0;
    }

    if (t->data == elem) {
        return l;
    }

    int x = find(t->left, elem, l + 1);
    if (x != 0) {
        return x;
    }
    x = find(t->right, elem, l + 1);
    return x;
}

template <typename T>
int getLevel(const Tree<T> *t, const T &elem) {
    if (t == nullptr) {
        return 0;
    }
    int l = 1;
    return find(t, elem, l);
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));

    printTree(t);
    cout << "Height: " << getLevel(t, 7);

    freeTree(t);
    return 0;
}