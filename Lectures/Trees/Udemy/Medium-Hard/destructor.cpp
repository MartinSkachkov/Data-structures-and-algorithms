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
void clear(Tree<T> *tree) {
    if (tree == nullptr) {
        return;
    }

    clear(tree->left);
    clear(tree->right);
    delete tree;
}

int main() {
    Tree<int> *t = new Tree<int>(3, new Tree<int>(2), new Tree<int>(1));

    clear(t);
    return 0;
}