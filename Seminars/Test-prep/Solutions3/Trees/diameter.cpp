#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
int height(Tree<T> *t) {
    int res = 1;

    if (t->left != nullptr) {
        res = 1 + height(t->left);
    }
    if (t->right != nullptr) {
        res = std::max(res, 1 + height(t->right));
    }

    return res;
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));
    Tree<int> *t2 = new Tree<int>(2, new Tree<int>(3, new Tree<int>(5, nullptr, new Tree<int>(8, nullptr, new Tree<int>(6, new Tree<int>(7, nullptr, new Tree<int>(15)), nullptr))), nullptr), new Tree<int>(3, nullptr, new Tree<int>(7)));

    assert(t != nullptr);
    assert(t2 != nullptr);
    cout << "Diameter: " << height(t->left) + height(t->right) + 1; // + 1 for the root
    cout << "Diameter: " << height(t2->left) + height(t2->right) + 1;

    freeTree(t);
    freeTree(t2);
    return 0;
}