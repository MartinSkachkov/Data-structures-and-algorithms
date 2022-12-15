#include <iostream>
using namespace std;

template <typename T>
struct Tree {
    T data;
    Tree<T> *left;
    Tree<T> *right;
    Tree(const T &d, Tree<T> *l = nullptr, Tree<T> *r = nullptr) : data(d), left(l), right(r) {}
};

template <typename T>
void traverse_left_boundry(const Tree<T> *root) {
    cout << root->data;

    if (root->left != nullptr) {
        traverse_left_boundry(root->left);
    } else if (root->right != nullptr) {
        traverse_left_boundry(root->right);
    }
}

template <typename T>
void clear(Tree<T> *tree) {
    if (tree == nullptr) {
        return;
    }

    clear(tree->left);
    clear(tree->right);
    delete tree;
}

int main() {
    Tree<int> *t = new Tree<int>(2, new Tree<int>(3, new Tree<int>(5, nullptr, new Tree<int>(8, nullptr, new Tree<int>(6, new Tree<int>(7, nullptr, new Tree<int>(15)), nullptr))), nullptr), new Tree<int>(3, nullptr, new Tree<int>(7)));
    traverse_left_boundry(t);

    clear(t);
    return 0;
}