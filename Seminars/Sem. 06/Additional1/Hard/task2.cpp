#include "tree-utils.h"

template <typename T>
bool flipEquiv(Tree<T> *root1, Tree<T> *root2) {
    // if one of the trees is empty
    if ((root1 == nullptr && root2 != nullptr) || (root1 != nullptr && root2 == nullptr)) {
        return false;
    } else if (root1 != nullptr) { // this will catch that root2 is not empty as well due to the first if cond
        return (root1->data == root2->data && ((flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right)) ||
                                               (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))));

    } else {
        return true;
    }
}