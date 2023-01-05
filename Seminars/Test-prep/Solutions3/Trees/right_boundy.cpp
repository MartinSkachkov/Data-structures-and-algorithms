#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
void right_boundry(Tree<T> *t) {
    cout << t->data << ' ';

    if (t->right != nullptr) {
        right_boundry(t->right);
    } else if (t->left != nullptr) {
        right_boundry(t->left);
    }
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));

    assert(t != nullptr && t->right != nullptr);
    printTree(t);
    cout << "Right Boundry: ";
    right_boundry(t);

    freeTree(t);
    return 0;
}