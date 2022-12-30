#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
void left_boundry(Tree<T> *t) {
    cout << t->data << ' ';

    // we will enter the if statement and traverse the left side and then when back tracking the recursion it will skip the else if part as it entered the first if
    if (t->left != nullptr) {
        left_boundry(t->left);
    } else if (t->right != nullptr) {
        left_boundry(t->right);
    }
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));

    assert(t != nullptr);
    cout << "Left Boundry: ";
    left_boundry(t);

    freeTree(t);
    return 0;
}