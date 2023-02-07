#include "tree-utils.h"

template <typename T>
vector<T> rightSideView(Tree<T> *t) {
    // if we have an empty tree return an empty vector
    if (t == nullptr) {
        vector<T> v;
        return v;
    }

    // if we have a single node or we reached a leaf create a vector, add the node value & return it
    if (t->left == nullptr && t->right == nullptr) {
        vector<T> v;
        v.push_back(t->data);
        return v;
    }

    // find just the right boundry
    vector<T> right; // here we will store the right boundry without the main root node

    if (t->right != nullptr) {
        right = rightSideView(t->right);
    } else if (t->left != nullptr) {
        right = rightSideView(t->left);
    }

    right.insert(right.begin(), t->data); // insert the main root node at the beginning of the path since this is where we start from

    return right;
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, new Tree<int>(20, new Tree<int>(8, nullptr, new Tree<int>(69))))));
    printTree(t);

    cout << "Right Boundry: ";
    vector<int> res = rightSideView(t);
    for (int x : res) {
        cout << x << ' ';
    }

    freeTree(t);
    return 0;
}