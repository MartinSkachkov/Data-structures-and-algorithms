#include "tree-utils.h"
#include <queue>

template <typename T>
void levelOrdTrav(Tree<T> *t) {
    // empty tree
    if (t == nullptr) {
        return;
    }

    queue<const Tree<T> *> q; // here we will save the nodes per level
    q.push(t);                // lv. 0

    while (!q.empty()) {
        const Tree<T> *curr = q.front();
        q.pop();

        cout << curr->data << ' ';

        // add left subtree root for the next level
        if (curr->left != nullptr) {
            q.push(curr->left);
        }
        // add right subtree root for the next level
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));
    Tree<int> *t2 = new Tree<int>(2, new Tree<int>(3, new Tree<int>(5, nullptr, new Tree<int>(8, nullptr, new Tree<int>(6, new Tree<int>(7, nullptr, new Tree<int>(15)), nullptr))), nullptr), new Tree<int>(3, nullptr, new Tree<int>(7)));

    printTree(t);
    levelOrdTrav(t);

    printTree(t2);
    levelOrdTrav(t2);

    freeTree(t);
    freeTree(t2);
    return 0;
}
