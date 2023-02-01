void remove_all_repeated_from_sorted() { // O(n) time - O(1) memory
    if (length <= 1)
        return;

    // Add dummy head for easier prv linking
    insert_front(-1234);

    tail = head;
    Node *previous = head;
    Node *cur = head->next; // Our actual head

    while (cur) {
        // 2 cases: Either blocks of repeated so remove it. Or single node, keep it

        // keep removing blocks of SAME value
        bool any_removed = false;
        while (cur && cur->next && cur->data == cur->next->data) {
            int block_value = cur->data;
            any_removed = true;
            while (cur && cur->data == block_value)
                cur = move_and_delete(cur);
        }
        if (any_removed) {
            if (!cur)
                tail = previous;
            previous->next = cur; // link after the removed nodes
            previous = cur;
        } else {
            // No duplicates. Connect and use as tail for now
            tail = cur;
            previous = cur;
            cur = cur->next;
        }
    }
    previous = head->next; // actual head
    delete_front();        // remove dummy head
    head = previous;
    if (!head)
        tail = head;
    debug_verify_data_integrity();
}
