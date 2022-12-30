#include "tree-utils.h"
#include <cassert>
#include <iostream>
using namespace std;

template <typename T>
int max_elem(Tree<T> *t) {
    int res = t->data;

    if (t->left != nullptr) {
        res = std::max(res, max_elem(t->left));
    }
    
    if (t->right != nullptr) {
        res = std::max(res, max_elem(t->right));
    }

    return res;
}

int main() {
    Tree<int> *t = new Tree<int>(2, new Tree<int>(43), new Tree<int>(13, new Tree<int>(7), new Tree<int>(8)));

    assert(t != nullptr);
    cout << "Max: " << max_elem(t);

    freeTree(t);
    return 0;
}