#include <iostream>
using namespace std;

template <typename T>
struct Tree {
    T data;
    Tree<T> *left;
    Tree<T> *right;
    Tree(const T &d, Tree<T> *l = nullptr, Tree<T> *r = nullptr) : data(d), left(l), right(r) {}
};

int bt_diameter(const Tree<T> *t, const T &elem1, const T &elem2) {
    int res = 0;

    if (t->left != nullptr &&) {
        res = 1 + bt_diameter(t->left);
    }
    if (t->right != nullptr) {
        res = max(res, 1 + bt_diameter(t->right));
    }
    return res;
}