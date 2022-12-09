#include "tree-utils.h"
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void level_order_trav(const Tree<T> *t) {
    queue<const Tree<T> *> q;
    q.push(t);

    while (!q.empty()) {
        const Tree<T> *currNode = q.front();
        q.pop();

        cout << currNode->data;
        if (currNode->left) {
            q.push(currNode->left);
        }
        if (currNode->right) {
            q.push(currNode->right);
        }
    }
}

int main() {
    Tree<int> *root = new Tree<int>(8, new Tree<int>(3, new Tree<int>(1), new Tree<int>(6, new Tree<int>(4), new Tree<int>(7))), new Tree<int>(10, nullptr, new Tree<int>(14, new Tree<int>(13))));

    level_order_trav(root); //изпечатва елементите на дървото сортирано
    std::cout << '\n';
    printTree(root);

    freeTree(root);
    return 0;
}