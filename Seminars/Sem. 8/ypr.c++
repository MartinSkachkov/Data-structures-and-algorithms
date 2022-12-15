#include <iostream>
using namespace std;

struct node {
    int val;            // value
    struct node *left;  // left child
    struct node *right; // right child
    int ht;             // height of the node
};

int get_ht(node *root) {
    if (root) {
        return root->ht;
    }
    return 0;
}

void insert(node *&root, int new_val) {
    if (root == nullptr) {
        root = new node{new_val, nullptr, nullptr, 0};
        return;
    }

    if (new_val < root->val) {
        insert(root->left, new_val);
    } else {
        insert(root->right, new_val);
    }
    root->ht = max(get_ht(root->left), get_ht(root->right)) + 1;
    
    int bf = get_ht(root->left) - get_ht(root->right);
    if (bf > 1) {

    }
}

void inorder_trav(node *tree) {
    if (tree == nullptr) {
        return;
    }

    inorder_trav(tree->left);
    cout << tree->val << ' ';
    inorder_trav(tree->right);
}

void freeMem(node *root) {
    if (root == nullptr) {
        return;
    }

    freeMem(root->left);
    freeMem(root->right);
    delete root;
}

int main() {
    node *root = new node{6, new node{3, nullptr, nullptr, 0}, new node{8, nullptr, nullptr, 0}, 1};
    insert(root, 30);
    inorder_trav(root);
    freeMem(root);
    return 0;
}
