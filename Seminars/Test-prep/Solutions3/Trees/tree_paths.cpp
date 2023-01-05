#include "tree-utils.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
vector<string> binTreePaths(const Tree<T> *t) {
    if (t == nullptr) {
        vector<string> v;
        return v;
    } else if (t->left == nullptr && t->right == nullptr) {
        vector<string> v;
        v.push_back(to_string(t->data));
        return v;
    }

    vector<string> left = binTreePaths(t->left);
    for (size_t i = 0; i < left.size(); i++) {
        left[i] = to_string(t->data) + " -> " + left[i];
    }

    vector<string> right = binTreePaths(t->right);
    for (size_t i = 0; i < right.size(); i++) {
        right[i] = to_string(t->data) + " -> " + right[i];
    }

    vector<string> res;

    for (auto x : left) {
        res.push_back(x);
    }
    for (auto y : right) {
        res.push_back(y);
    }

    return res;
}

int main() {
    Tree<int> *t = new Tree<int>(10, new Tree<int>(5, nullptr, new Tree<int>(8, new Tree<int>(6))), new Tree<int>(15, new Tree<int>(13, nullptr, new Tree<int>(14)), new Tree<int>(19, new Tree<int>(18), new Tree<int>(20))));

    printTree(t);
    vector<string> res = binTreePaths(t);
    for (auto x : res) {
        cout << x << endl;
    }

    freeTree(t);
    return 0;
}
