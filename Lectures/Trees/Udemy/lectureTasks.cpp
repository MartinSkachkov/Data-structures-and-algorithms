#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *left;
    Node<T> *right;
    Node(const T &d, Node<T> *l = nullptr, Node<T> *r = nullptr) : data(d), left(l), right(r) {}
};

// THINK ABOUT WHAT?, NOT HOW?

// + 2 3 a.k.a curr->data, left, right
template <typename T>
void pre_print(Node<T> *node) {
    if (node == nullptr) {
        return;
    }

    cout << node->data << ' ';
    pre_print(node->left);  // first we print the content of the left subtree
    pre_print(node->right); // then we print the content of the rigth subtree
}

// 2 + 3 a.k.a left, curr->data, right
template <typename T>
void infx_print(Node<T> *node) {
    if (node == nullptr) {
        return;
    }

    infx_print(node->left);
    cout << node->data << ' ';
    infx_print(node->right);
}

// 2 3 + a.k.a left, right, curr->data
template <typename T>
void post_print(Node<T> *node) {
    if (node == nullptr) {
        return;
    }

    post_print(node->left);
    post_print(node->right);
    cout << node->data << ' ';
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

// {2, 4, 7} {'L', 'L', 'R'}
template <typename T>
void createTree(vector<int> values, vector<char> path, Node<T> *node) {
    assert(values.size() == path.size());
    for (size_t i = 0; i < values.size(); i++) {
        if (path[i] == 'L') {
            if (node->left == nullptr) {
                node->left = new Node<T>(values[i]);
            } else {
                assert(node->left->data == values[i]);
                node = node->left;
            }
        } else {
            if (node->right == nullptr) {
                node->right = new Node<T>(values[i]);
            } else {
                assert(node->right->data == values[i]);
                node = node->right;
            }
        }
    }
}

int main() {
    // Create Nodes
    /* Node<int> *root = new Node<int>(1);
     Node<int> *node2 = new Node<int>(2);
     Node<int> *node3 = new Node<int>(3);
     Node<int> *node4 = new Node<int>(4);
     Node<int> *node5 = new Node<int>(5);
     Node<int> *node6 = new Node<int>(6);
     Node<int> *node7 = new Node<int>(7);
     Node<int> *node8 = new Node<int>(8);

     // Link them!
     root->left = node2;
     root->right = node3;

     node2->left = node4;
     node2->right = node5;

     node5->right = node7;

     node3->right = node6;

     node6->left = node8;

     cout << root->left->right->right->data << "\n"; // 7
     cout << node2->right->right->data << "\n";      // 7
     cout << node5->right->data << "\n";             // 7
     cout << node7->data << "\n";                    // 7

     cout << root->right->right->data << "\n";       // 6
     cout << root->right->right->left->data << "\n"; // 8
     cout << root->right->right->right << "\n";      // 0x00
     cout << endl;
     // pre_print(root);*/

    Node<char> *plus = new Node<char>('+', new Node<char>('2'), new Node<char>('3')); // print in a prefix notation

    pre_print(plus);
    cout << endl;
    post_print(plus);
    cout << endl;
    infx_print(plus);

    Node<int> *root = new Node<int>(1);
    createTree({2, 4, 7}, {'L', 'L', 'L'}, root);
    createTree({2, 4, 8}, {'L', 'L', 'R'}, root);
    createTree({2, 5, 9}, {'L', 'R', 'R'}, root);
    createTree({3, 6, 10}, {'R', 'R', 'L'}, root);

    infx_print(root);
    free(root);
    // free the memory
    /* delete root;
     delete node2;
     delete node3;
     delete node4;
     delete node5;
     delete node6;
     delete node7;
     delete node8;*/
    free(plus);
    return 0;
}