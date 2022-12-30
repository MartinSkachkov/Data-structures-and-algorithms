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
void free(Tree<T> *t) {
    if (t == nullptr) {
        return;
    }
    free(t->left);  // left child
    free(t->right); // right child
    delete t;       // delete mid
}

template <typename T>
void prefix_traversal(const Tree<T> *t) {
    if (t == nullptr) {
        return;
    }

    cout << t->data << ' ';
    prefix_traversal(t->left);
    prefix_traversal(t->right);
}

template <typename T>
void infix_traversal(const Tree<T> *t) {
    if (t == nullptr) {
        return;
    }

    infix_traversal(t->left);
    cout << t->data << ' ';
    infix_traversal(t->right);
}

template <typename T>
void postfix_traversal(const Tree<T> *t) {
    if (t == nullptr) {
        return;
    }

    postfix_traversal(t->left);
    postfix_traversal(t->right);
    cout << t->data << ' ';
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8))));

    cout << "Prefix: ";
    prefix_traversal(t);

    cout << "Infix: ";
    infix_traversal(t);

    cout << "Postfix: ";
    postfix_traversal(t);

    free(t);
    return 0;
}