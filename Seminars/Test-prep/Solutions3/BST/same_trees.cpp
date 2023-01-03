#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
bool sameTrees(const Tree<T> *fst, const Tree<T> *snd) {
    // base case
    if (fst == nullptr && snd == nullptr) {
        return true;
    }

    // conditions for different trees
    if ((fst == nullptr && snd != nullptr) || (fst != nullptr && snd == nullptr) || (fst->data != snd->data)) {
        return false;
    }

    return sameTrees(fst->left, snd->left) && sameTrees(fst->right, snd->right);
}

int main() {
    Tree<int> *example = new Tree<int>(4, new Tree<int>(2), new Tree<int>(6));
    Tree<int> *example2 = new Tree<int>(4, new Tree<int>(2), new Tree<int>(6));

    cout << sameTrees(example, example2);

    freeTree(example);
    freeTree(example2);
    return 0;
}