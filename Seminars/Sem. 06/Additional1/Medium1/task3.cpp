#include "tree-utils.h"

template <typename T>
vector<T> leftBoundry(Tree<T> *t) {
    // empty tree doesn't have boundries so we return an empty vector
    if (t == nullptr) {
        vector<T> v;
        return v;
    }

    // single node tree || leaf node
    if (t->left == nullptr && t->right == nullptr) {
        vector<T> v;          // create the vector
        v.push_back(t->data); // add the single data to it
        return v;
    }

    // we have more than a single node
    vector<T> leftB; // here we will save the result

    if (t->left != nullptr) { // start traversing the left subtree
        leftB = leftBoundry(t->left);
    } else if (t->right != nullptr) { // if we can't go more to the left ttry going to the right
        leftB = leftBoundry(t->right);
    }

    leftB.insert(leftB.begin(), t->data);

    return leftB;
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));

    printTree(t);
    vector<int> res = leftBoundry(t);
    cout << "Left Boundry: ";
    for (int x : res) {
        cout << x << ' ';
    }

    freeTree(t);
    return 0;
}