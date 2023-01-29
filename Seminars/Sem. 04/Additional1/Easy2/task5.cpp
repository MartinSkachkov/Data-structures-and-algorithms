// template solution

void sortedInsert(ListNode *&head, int val) {
    ListNode *node = new ListNode(val);
    ListNode *pre = NULL;
    ListNode *curr = head;

    while (curr != NULL && val > curr->val) {
        pre = curr;
        curr = curr->next;
    }
    node->next = curr;
    if (pre == NULL) {
        head = node;
    } else {
        pre->next = node;
    }
}