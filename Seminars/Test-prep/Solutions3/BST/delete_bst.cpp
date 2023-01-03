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
void freeTree(Tree<T> *t) {
    if (t == nullptr) {
        return;
    }
    freeTree(t->left);
    freeTree(t->right);
    delete t;
}

template <typename T>
void insert(Tree<T> *&t, const T &elem) {
    // if the root is null, create a new node and return it
    if (t == nullptr) {
        t = new Tree<T>(elem);
        return;
    }

    // if the given key is less than the root node, recur for the left subtree
    if (elem < t->data) {
        insert(t->left, elem);
    }

    // if the given key is more than the root node, recur for the right subtree
    if (elem > t->data) {
        insert(t->right, elem);
    }
}

template <typename T>
void inorder(Tree<T> *t) {
    if (t == nullptr) {
        return;
    }
    inorder(t->left);
    cout << t->data << ' ';
    inorder(t->right);
}

template <typename T>
Tree<T> *findMaxEl(Tree<T> *t) {
    while (t->right != nullptr) {
        t = t->right;
    }
    return t;
}

// Function to delete a node from a BST. Note that root is passed by
// reference to the function
template <typename T>
void deleteNode(Tree<T> *&t, const T &elem) {
    // base case: the key is not found in the tree
    if (t == nullptr) {
        return;
    }

    // if the given key is less than the root node, recur for the left subtree
    if (elem < t->data) {
        deleteNode(t->left, elem);
    }

    // if the given key is more than the root node, recur for the right subtree
    if (elem > t->data) {
        deleteNode(t->right, elem);
    }

    // key found
    if (elem == t->data) {
        // Case 1: node to be deleted has no children (it is a leaf node)
        if (t->left == nullptr && t->right == nullptr) {
            // deallocate the memory and update root to null
            delete t;
            t = nullptr;
        }

        // Case 2: node to be deleted has two children
        else if (t->left != nullptr && t->right != nullptr) {
            // find its inorder predecessor node
            Tree<T> *pred = findMaxEl(t->left);

            // copy value of the predecessor to the current node
            t->data = pred->data;

            // recursively delete the predecessor
            deleteNode(t->left, pred->data);
        }

        // Case 3: node to be deleted has only one child
        else {
            Tree<T> *child = (t->left) ? t->left : t->right;
            Tree<T> *curr = t;

            t = child;

            // deallocate the memory
            delete curr;
        }
    }
}

int main() {
    // int elems[] = {15, 10, 20, 8, 12, 25};
    int elems1[] = {3, 4, 5};

    Tree<int> *t = nullptr;
    for (int x : elems1) {
        insert(t, x);
    }

    cout << "Tree: ";
    inorder(t);

    // deleteNode(t, 15);
    // deleteNode(t, 25);
    // deleteNode(t, 20);
    cout << "Tree: ";
    inorder(t);

    freeTree(t);
    return 0;
}