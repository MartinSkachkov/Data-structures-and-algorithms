#include <cmath>
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(const T &d, Node<T> *l = nullptr, Node<T> *r = nullptr) : data(d), left(l), right(r) {}
};

template <typename T>
void freeTree(Node<T> *node) {
    if (node == nullptr) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

template <typename T>
int total_nodes(Node<T> *node) {
    int res = 0;

    if (node->left != nullptr) {
        res += 1 + total_nodes(node->left);
    }
    if (node->right != nullptr) {
        res += 1 + total_nodes(node->right);
    }

    return res;
}

template <typename T>
int tree_height(Node<T> *node) {
    int res = 0;

    if (node->left != nullptr) {
        res = 1 + tree_height(node->left);
    }
    if (node->right != nullptr) {
        res = max(res, 1 + tree_height(node->right));
    }

    return res;
}

template <typename T>
bool is_perfect_formula(Node<T> *node) {
    return pow(2, tree_height(node) + 1) - 1 == total_nodes(node) + 1;
}

template <typename T>
bool is_perfect(Node<T> *node, int h = -1) {
    if (h == -1) // first call
        h = tree_height(node);

    // All leaves must be on the same last level
    if (!node->left && !node->right)
        return h == 0;

    if (!node->left && node->right || node->left && !node->right)
        return false; // one child!

    // perfect on level h is perfect on h-1 for children
    return is_perfect(node->left, h - 1) && is_perfect(node->right, h - 1);
}

int main() {
    Node<int> *root = new Node<int>(2, new Node<int>(3, new Node<int>(4), new Node<int>(5)), new Node<int>(13, new Node<int>(7), new Node<int>(8)));
    cout << '\n'
         << is_perfect_formula(root) << '\n';
    cout << '\n'
         << is_perfect(root) << '\n';
    freeTree(root);
    return 0;
}