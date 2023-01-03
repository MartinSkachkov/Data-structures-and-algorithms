#include "tree-utils.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

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
Tree<T> *buildFromVec(const vector<T> &v, int start, int end) {
    if (end < start) {
        return nullptr;
    }

    int mid = (end - start) / 2 + start;

    return new Tree<T>(v[mid], buildFromVec(v, start, mid - 1), buildFromVec(v, mid + 1, end));
}

int main() {
    vector<int> v = {8, 10, 12, 15, 20, 25};
    Tree<int> *t = buildFromVec(v, 0, v.size() - 1);
    cout << "Root: " << t->data << endl;
    cout << "Tree: ";
    inorder(t);

    freeTree(t);
    return 0;
}