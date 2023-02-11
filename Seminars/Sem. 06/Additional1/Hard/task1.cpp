#include "tree-utils.h"

template <typename T>
bool isSymmetric(Tree<T> *first, Tree<T> *second) {
    // if both trees are empty then they are symmetrical
    if (first == nullptr && second == nullptr) {
        return true;
    }

    // case when they are not
    if ((first == nullptr && second != nullptr) || (second == nullptr && first != nullptr) || (first->data != second->data)) {
        return false;
    }

    return isSymmetric(first->left, second->right) && isSymmetric(first->right, second->left);
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(3), new Tree<int>(4)), new Tree<int>(2, new Tree<int>(4), new Tree<int>(3)));
    Tree<int> *t1 = new Tree<int>(1, new Tree<int>(2, new Tree<int>(3), new Tree<int>(4)), new Tree<int>(2, new Tree<int>(4), new Tree<int>(5)));
    printTree(t);

    cout << isSymmetric(t, t);
    cout << isSymmetric(t1, t1);

    freeTree(t);
    freeTree(t1);
    return 0;
}
