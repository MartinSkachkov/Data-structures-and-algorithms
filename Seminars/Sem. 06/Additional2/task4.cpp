#include "tree-utils.h"
#include <queue>

template <typename T>
vector<vector<T>> zigZagTrav(Tree<T> *t) {
    // if the tree is empty return an empty vector
    if (t == nullptr) {
        vector<vector<int>> v;
        return v;
    }

    vector<vector<int>> res;  // here we will save each level traversal
    queue<const Tree<T> *> q; // here we will save the tree nodes
    q.push(t);                // add the root node

    bool leftToRight = true; // since it's zig zag traversal this will determine how we will write the values from each row

    while (!q.empty()) {
        int queueSize = q.size();
        vector<int> row(queueSize); // here we will save the level traversal for individual row

        for (size_t i = 0; i < row.size(); i++) {
            const Tree<T> *curr = q.front(); // get the current element
            q.pop();                         // remove it so that we not repeat it again

            // save the curr data to the row
            int indx = leftToRight ? i : row.size() - 1 - i; // determine if we will write to the front(leftToRight) or to the back(rightToLeft)
            row[indx] = curr->data;

            // add the following nodes for the next iteration
            if (curr->left != nullptr) {
                q.push(curr->left);
            }

            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }

        // once done adding all elements from the current row
        res.push_back(row);
        leftToRight = !leftToRight;
    }

    return res;
}

int main() {
    Tree<int> *t = new Tree<int>(10, new Tree<int>(5, nullptr, new Tree<int>(8, new Tree<int>(6))), new Tree<int>(15, new Tree<int>(13, nullptr, new Tree<int>(14)), new Tree<int>(19, new Tree<int>(18), new Tree<int>(20))));

    printTree(t);
    vector<vector<int>> res = zigZagTrav(t);

    for (vector<int> v : res) {
        for (int x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    freeTree(t);
    return 0;
}