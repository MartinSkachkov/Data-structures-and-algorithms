#include "tree-utils.h"
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void insertLevelOrd(Tree<T> *&t, T data) {
    if (t == nullptr) {
        t = new Tree<T>(data);
        return;
    }

    queue<Tree<T> *> q;
    q.push(t);

    while (!q.empty()) {
        Tree<T> *curr = q.front();
        q.pop();

        if (curr->left != nullptr) {
            q.push(curr->left);
        } else {
            curr->left = new Tree<T>(data);
            return;
        }

        if (curr->right != nullptr) {
            q.push(curr->right);
        } else {
            curr->right = new Tree<T>(data);
            return;
        }
    }
}

int main() {
    Tree<int> *t = nullptr;
    int arr[] = {10, 20, 30, 40, 50, 60};
    for (int i : arr) {
        insertLevelOrd(t, i);
    }

    printTree(t);

    freeTree(t);
    return 0;
}