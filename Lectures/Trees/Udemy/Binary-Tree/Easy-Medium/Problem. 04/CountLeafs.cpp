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
void prefix_print(Node<T> *node) {
    if (node == nullptr) {
        return;
    }

    cout << node->data << ' ';
    prefix_print(node->left);
    prefix_print(node->right);
}

template <typename T>
void free(Node<T> *node) {
    if (node == nullptr) {
        return;
    }

    free(node->left);
    free(node->right);
    delete node;
}

int count_leafs(Node<int> *curr) {
    int res = !curr->left && !curr->right;
    if (curr->left != nullptr) {
        res += count_leafs(curr->left);
    }
    if (curr->right != nullptr) {
        res += count_leafs(curr->right);
    }
    return res;
}

int main() {
    Node<int> *root = new Node<int>(2, new Node<int>(3), new Node<int>(13, new Node<int>(7), new Node<int>(8)));
    prefix_print(root);
    cout << endl
         << "Leafs: " << count_leafs(root);
    free(root);
    return 0;
}