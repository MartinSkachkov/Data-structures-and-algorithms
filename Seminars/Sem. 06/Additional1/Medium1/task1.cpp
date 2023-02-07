#include <iostream>
using namespace std;

template <typename T>
struct Tree {
    T data;
    Tree<T> *left;
    Tree<T> *right;

    Node(const T &d, Tree<T> *l, Tree<T> *r) : data(d), left(l), right(r) {}
};

template <typename T>
void deleteTree(Tree<T> *t) {
    // there is nothing to delete in an empty tree
    if (t == nullptr) {
        return;
    }

    deleteTree(t->left);
    deleteTree(t->right);
    delete t;
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, new Tree<int>(55, new Tree<int>(56, nullptr, new Tree<int>(56, new Tree<int>(56)))), new Tree<int>(69)))));

    deleteTree(t);
    return 0;
}