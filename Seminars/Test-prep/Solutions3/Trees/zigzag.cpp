#include "tree-utils.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> zigzagLevelOrder(Tree<int> *t) {
    if (t == nullptr) {
        vector<vector<int>> v;
        return v;
    }

    vector<vector<int>> res;
    queue<Tree<int> *> q;
    q.push(t);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> row(size);

        for (size_t i = 0; i < size; i++) {
            Tree<int> *curr = q.front();
            q.pop();

            int indx = leftToRight ? i : size - 1 - i;
            row[indx] = curr->data;

            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
        leftToRight = !leftToRight;
        res.push_back(row);
    }
    return res;
}

int main() {
    Tree<int> *t = new Tree<int>(10, new Tree<int>(5, nullptr, new Tree<int>(8, new Tree<int>(6))), new Tree<int>(15, new Tree<int>(13, nullptr, new Tree<int>(14)), new Tree<int>(19, new Tree<int>(18), new Tree<int>(20))));

    printTree(t);
    for (auto x : zigzagLevelOrder(t)) {
        for (auto y : x) {
            cout << y << ' ';
        }
    }

    freeTree(t);
    return 0;
}