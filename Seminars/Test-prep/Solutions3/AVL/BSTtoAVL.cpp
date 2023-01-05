#include "tree-utils.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void inorder(const Tree<T> *t, vector<T> &v) {
    if (t == nullptr) {
        return;
    }

    inorder(t->left, v);
    v.push_back(t->data);
    inorder(t->right, v);
}

template <typename T>
Tree<T> *convertToAvl(const vector<T> &v, int start, int end) {
    if (end < start) {
        return nullptr;
    }

    int mid = (end - start) / 2 + start;

    return new Tree<T>(v[mid], convertToAvl(v, start, mid - 1), convertToAvl(v, mid + 1, end));
}

int main() {
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
    // do inorder trav on the bst -> save elems to vector -> construct bst from vector

    Tree<int> *bst = new Tree<int>(10, new Tree<int>(8, new Tree<int>(7, new Tree<int>(6, new Tree<int>(5)))));

    printTree(bst);

    vector<int> v;
    inorder(bst, v);

    Tree<int> *avl = convertToAvl(v, 0, v.size() - 1);
    printTree(avl);

    freeTree(bst);
    freeTree(avl);
    return 0;
}