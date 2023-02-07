#include <iostream>
using namespace std;

template <typename T>
struct Tree {
    T data;
    Tree<T> *left;
    Tree<T> *right;

    Tree(const T &d, Tree<T> *l = nullptr, Tree<T> *r = nullptr) : data(d), left(l), right(r) {}
};

// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
template <class T>
void printBT(const std::string &prefix, const Tree<T> *node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "`--");

        std::cout << node->data << std::endl;

        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

template <class T>
void printTree(const Tree<T> *node) {
    printBT("", node, false);
}

//   5
//  / \
// 2   3
template <typename T>
void freeTree(Tree<T> *t) {
    if (t == nullptr) {
        return;
    }

    // post order deletion
    freeTree(t->left);
    freeTree(t->right);
    delete t;
}

template <typename T>
void inorder(Tree<T> *t) {
    if (t == nullptr) {
        return;
    }

    // first we print the left subtree, than the value and then the right subtree
    inorder(t->left);
    cout << t->data << ' ';
    inorder(t->right);
}

template <typename T>
void preorder(Tree<T> *t) {
    if (t == nullptr) {
        return;
    }

    // first we print the current root value, then the left subtree and then the right subtree
    cout << t->data << ' ';
    preorder(t->left);
    preorder(t->right);
}

template <typename T>
void postorder(Tree<T> *t) {
    if (t == nullptr) {
        return;
    }

    // first we print the left subtree, then the right subtree and lastly the root value
    postorder(t->left);
    postorder(t->right);
    cout << t->data << ' ';
}

int main() {
    Tree<int> *t = new Tree<int>(5, new Tree<int>(4, new Tree<int>(1, nullptr, new Tree<int>(2))), new Tree<int>(3));

    printTree(t);
    cout << '\n';

    inorder(t);
    cout << '\n';

    preorder(t);
    cout << '\n';

    postorder(t);
    cout << '\n';

    freeTree(t);
    return 0;
}