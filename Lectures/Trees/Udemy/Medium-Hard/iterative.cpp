void print_inorder_iterative() {
    // Pair: node and it has been expanded or not so far
    stack<pair<BinaryTree *, bool>> nodes;

    // Just convert the recursion to calls
    nodes.push(make_pair(this, false));

    while (!nodes.empty()) {
        BinaryTree *current = nodes.top().first;
        bool is_done = nodes.top().second;
        nodes.pop();

        // If expanded already and we are here, then we just returned from recursion. Print
        if (is_done)
            cout << current->data << " ";
        else {
            // Push your children and mark yourself as expanded
            // Observe: put right, then left as stack verse things. We need left prossed first
            if (current->right)
                nodes.push(make_pair(current->right, false));

            nodes.push(make_pair(current, true));

            if (current->left)
                nodes.push(make_pair(current->left, false));
        }
    }
    cout << "\n";
    // There is another way for this problem based on tracing the nodes in order
    // e.g. keep expand left and add to stack
    // But approach here is nicer as it follows the recurrance itself (generic style)
}