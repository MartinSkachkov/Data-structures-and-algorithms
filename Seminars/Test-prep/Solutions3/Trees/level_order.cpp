#include "tree-utils.h"
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void levelOrderTrav(const Tree<T> *t) {
    if (t == nullptr) {
        cout << "Empty tree!";
        return;
    }

    queue<const Tree<T> *> q;
    q.push(t);

    while (!q.empty()) {
        const Tree<T> *curr = q.front();
        q.pop();

        cout << curr->data << ' ';

        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));

    printTree(t);
    levelOrderTrav(t);

    freeTree(t);
    return 0;
}