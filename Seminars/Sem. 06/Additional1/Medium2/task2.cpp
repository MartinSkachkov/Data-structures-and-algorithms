#include "tree-utils.h"
#include <queue>

template <typename T>
vector<vector<T>> spiralTraverse(Tree<T> *t) {
    // empty tree -> nothing to traverse
    if (t == nullptr) {
        vector<vector<T>> v;
        return v;
    }

    vector<vector<T>> res; // here we will save ach level
    queue<const Tree<T> *> q;
    q.push(t); // lv. 0

    bool leftToRight = true; // needed to create this spiral way of moving

    while (!q.empty()) {
        int levelSize = q.size();
        vector<T> row(levelSize);

        for (size_t i = 0; i < row.size(); i++) {
            const Tree<T> *curr = q.front();
            q.pop();

            int indx = leftToRight ? i : row.size() - 1 - i;
            row[indx] = curr->data;

            // add the nodes for the next level
            if (curr->left != nullptr) {
                q.push(curr->left);
            }

            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }

        // store the curren level to the result
        res.push_back(row);
        leftToRight = !leftToRight; // change the order of traversal
    }

    return res;
}

int main() {
    Tree<int> *t = new Tree<int>(1, new Tree<int>(2, new Tree<int>(4), new Tree<int>(5, nullptr, new Tree<int>(7))), new Tree<int>(3, nullptr, new Tree<int>(6, nullptr, new Tree<int>(8, nullptr, new Tree<int>(69)))));
    Tree<int> *t2 = new Tree<int>(2, new Tree<int>(3, new Tree<int>(5, nullptr, new Tree<int>(8, nullptr, new Tree<int>(6, new Tree<int>(7, nullptr, new Tree<int>(15)), nullptr))), nullptr), new Tree<int>(3, nullptr, new Tree<int>(7)));

    printTree(t);
    vector<vector<int>> res = spiralTraverse(t);

    for (vector<int> v : res) {
        for (int x : v) {
            cout << x << ' ';
        }
    }

    printTree(t2);
    res = spiralTraverse(t2);

    for (vector<int> v : res) {
        for (int x : v) {
            cout << x << ' ';
        }
    }

    freeTree(t);
    freeTree(t2);
    return 0;
}