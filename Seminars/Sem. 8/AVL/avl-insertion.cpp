#include "tree-utils.h"
#include <iostream>
#include <vector>
using namespace std;

/*
 AVL дървото е двоично наредено дърво (Binary Search Tree), но с допълнението, че е балансирано (височината на лявото поддърво
 се различава максимум с единица от височината на дясното поддърво)
*/

template <typename T>
void insertBST(Tree<T> *&tree, const T &value) {
    if (tree == nullptr) {
        tree = new Tree<T>(value);
        return;
    }

    if (tree->data < value) {
        insertBST(tree->right, value);
    }
    if (tree->data > value) {
        insertBST(tree->left, value);
    }
}

template <typename T>
void inorder_trav(const Tree<T> *tree, vector<T> &v) {
    if (tree == nullptr) {
        return;
    }

    inorder_trav(tree->left, v);
    v.push_back(tree->data);
    inorder_trav(tree->right, v);
}

template <typename T>
Tree<T> *buildTree(const vector<T> &v, int start, int end) {
    if (end < start) {
        return nullptr;
    }

    int mid = (end - start) / 2 + start;

    return new Tree<T>(v[mid], buildTree(v, start, mid - 1), buildTree(v, mid + 1, end));
}

int main() {
    Tree<int> *example = new Tree<int>(7, new Tree<int>(6, new Tree<int>(5, new Tree<int>(2))), new Tree<int>(8));
    printTree(example);

    // after the insertion
    insertBST(example, 1);
    printTree(example);

    // saving the data from the tree to a vector
    vector<int> v;
    inorder_trav(example, v);
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << '\n';

    // building an AVL tree from the vector
    Tree<int> *t = buildTree(v, 0, v.size() - 1);
    printTree(t);

    freeTree(t);
    freeTree(example);
    return 0;
}