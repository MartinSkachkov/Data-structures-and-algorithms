#include "tree-utils.h"
#include <vector>
using namespace std;

template <typename T>
vector<string> generateAllPaths(Tree<T> *t) {
    // if the tree is empty return an empty vector
    if (t == nullptr) {
        vector<string> v;
        return v;
    }

    // if we reached a leaf create a vector and push back the node's value
    if (t->left == nullptr && t->right == nullptr) {
        vector<string> v;
        v.push_back(to_string(t->data));
        return v;
    }

    // find all path on the left subtree
    vector<string> left = generateAllPaths(t->left);
    for (size_t i = 0; i < left.size(); i++) {
        left[i] = to_string(t->data) + "->" + left[i]; // append the root at the beginning since this is the start of every path
    }

    // find all paths on the right subtree
    vector<string> right = generateAllPaths(t->right);
    for (size_t i = 0; i < right.size(); i++) {          // for every possible path in the right subtree
        right[i] = to_string(t->data) + "->" + right[i]; // append the root at the beginning since this is the start of every path
    }

    // now save the data from left & right vector to one
    vector<string> allPaths;

    for (string p : left) {
        allPaths.push_back(p);
    }
    for (string p : right) {
        allPaths.push_back(p);
    }

    return allPaths;
}

int main() {
    Tree<int> *t = new Tree<int>(5, new Tree<int>(4, new Tree<int>(1, nullptr, new Tree<int>(2))), new Tree<int>(3));
    Tree<int> *t2 = new Tree<int>(1, new Tree<int>(2, nullptr, new Tree<int>(5)), new Tree<int>(3));

    vector<string> res = generateAllPaths(t);
    for (string p : res) {
        cout << p << '\n';
    }

    res = generateAllPaths(t2);
    for (string p : res) {
        cout << p << '\n';
    }

    freeTree(t);
    return 0;
}