#include "tree-utils.h"
#include <iostream>
using namespace std;

template <typename T>
bool areEqual(Tree<T> *t1, Tree<T> *t2) {
    if (t1 == nullptr && t2 == nullptr) {
        return true;
    }

    if (t1->data != t2->data) {
        return false;
    }

    return areEqual(t1->left, t2->left) && areEqual(t1->right, t2->right);
}

int main() {
    Tree<int> *t1 = new Tree<int>(15, new Tree<int>(10, new Tree<int>(9, new Tree<int>(8, new Tree<int>(7))), new Tree<int>(12)), new Tree<int>(19));
    Tree<int> *t2 = new Tree<int>(15, new Tree<int>(10, new Tree<int>(9, new Tree<int>(8, new Tree<int>(7))), new Tree<int>(12)), new Tree<int>(19));
    cout << boolalpha << areEqual(t1, t2) << '\n';

    Tree<int> *t3 = new Tree<int>(69, new Tree<int>(10, new Tree<int>(9, new Tree<int>(8, new Tree<int>(7)))), new Tree<int>(19));
    cout << boolalpha << areEqual(t1, t3) << '\n';

    freeTree(t1);
    freeTree(t2);
    return 0;
}