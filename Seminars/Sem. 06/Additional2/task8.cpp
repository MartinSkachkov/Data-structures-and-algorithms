#include "tree-utils.h"

int evaluate(Tree<string> *t) {
    // if we have an empty tree the result will be 0
    if (t == nullptr) {
        return 0;
    }

    // if we have a single node or we reached a child then return the value of the node
    if (t->left == nullptr && t->right == nullptr) {
        return stoi(t->data);
    }

    // evaluate left subtree
    int leftEval = evaluate(t->left);

    // evaluate right subtree
    int rightEval = evaluate(t->right);

    // execute the operation in the root node
    if (t->data == "+")
        return leftEval + rightEval;
    if (t->data == "-")
        return leftEval - rightEval;
    if (t->data == "/")
        return leftEval / rightEval;
    return leftEval * rightEval;
}

int main() {
    Tree<string> *t = new Tree<string>("+", new Tree<string>("*", new Tree<string>("5"), new Tree<string>("4")), new Tree<string>("-", new Tree<string>("100"), new Tree<string>("/", new Tree<string>("20"), new Tree<string>("2"))));
    printTree(t);

    int res = evaluate(t);
    cout << "Result: " << res;

    freeTree(t);
    return 0;
}