#include "tree-utils.h"

bool doesExist(Tree<int> *t, int elem) {
    // empty tree has no elements so it doesn't exist
    if (t == nullptr) {
        return false;
    }

    // found the element
    if (t->data == elem) {
        return true;
    }

    bool found = false;                         // we haven't found it yet
    found = found || doesExist(t->left, elem);  // check left subtree
    found = found || doesExist(t->right, elem); // check right subtree

    return found;
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));

    printTree(t);
    cout << "Exists: " << doesExist(t, -6) << '\n';
    cout << "Exists: " << doesExist(t, 69) << '\n';
    cout << "Exists: " << doesExist(t, 5) << '\n';
    cout << "Exists: " << doesExist(t, 20) << '\n';

    freeTree(t);
    return 0;
}