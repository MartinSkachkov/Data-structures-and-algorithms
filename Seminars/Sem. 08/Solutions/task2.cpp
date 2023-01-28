#include "tree-utils.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
Tree<T> *buildFromVector(vector<T> &v, int start, int end) {
    if (end < start) {
        return nullptr;
    }

    int mid = (end - start) / 2 + start;

    return new Tree<T>(v[mid], buildFromVector(v, start, mid - 1), buildFromVector(v, mid + 1, end));
}

int main() {
    vector<int> v;
    for (size_t i = 0; i < 8; i++) {
        v.push_back(i);
    }

    for (size_t i = 0; i < 8; i++) {
        cout << v[i];
    }

    Tree<int> *t = buildFromVector(v, 0, v.size() - 1);
    printTree(t);

    freeTree(t);
    return 0;
}