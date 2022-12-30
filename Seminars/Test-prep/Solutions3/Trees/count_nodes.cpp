#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
int count_nodes(Tree<T> *t) {
    int res = 1;

    if (t->left != nullptr) {
        res += count_nodes(t->left);
    }

    if (t->right != nullptr) {
        res += count_nodes(t->right);
    }

    return res;
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));

    assert(t != nullptr);
    cout << "Nodes: " << count_nodes(t);

    freeTree(t);
    return 0;
}
