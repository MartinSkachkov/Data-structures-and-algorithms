#include "tree-utils.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename T = int>
void inorder(Tree<T> *t, vector<T> &v) {
    if (t == nullptr) {
        return;
    }

    inorder(t->left, v);
    v.push_back(t->data);
    inorder(t->right, v);
}

template <typename T = int>
T kthSmallest(Tree<T> *t, int k) {
    vector<int> v;
    inorder(t, v);
    sort(v.begin(), v.end());

    return v[k];
}

int mian() {
    Tree<int> *t = new Tree<int>(10, new Tree<int>(5, nullptr, new Tree<int>(8, new Tree<int>(6))), new Tree<int>(15, new Tree<int>(13, nullptr, new Tree<int>(14)), new Tree<int>(19, new Tree<int>(18), new Tree<int>(20))));

    printTree(t);
    cout << kthSmallest(t, 3);

    freeTree(t);
    return 0;
}