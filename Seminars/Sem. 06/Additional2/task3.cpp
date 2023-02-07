#include "tree-utils.h"
#include <queue>

template <typename T>
void levelOrderTrav(Tree<T> *t) {
    // if the tree is empty just break
    if (t == nullptr) {
        return;
    }

    queue<const Tree<T> *> q; // first we create an empty queue
    q.push(t);                // then we add the current node

    while (!q.empty()) {
        const Tree<T> *curr = q.front(); // get the current Node in the queue
        q.pop();                         // remove it so that we don't repeat it

        cout << curr->data; // print the value

        // add the left subtree root node
        if (curr->left != nullptr) {
            q.push(curr->left);
        }

        // add the right subtree root node
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