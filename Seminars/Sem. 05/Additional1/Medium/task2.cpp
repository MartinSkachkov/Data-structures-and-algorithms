/*
 * The idea is easy, but several test specail cases
 * 1) Easy: no such node
 * 2) Easy: same node
 * 3) They are consecutive but 2 cases: first last or last first
 */
void swap_kth(int k) {
    if (k > length)
        return;
    int kth_back = length - k + 1;

    if (k == kth_back)
        return; // same node

    if (k > kth_back)
        swap(k, kth_back);

    Node *first = get_nth(k);
    Node *last = get_nth(kth_back);

    Node *first_prev = first->prev;
    Node *first_next = first->next;

    Node *last_prev = last->prev;
    Node *last_next = last->next;

    if (k + 1 == kth_back) { // consecutive (neighbours)
        link(first_prev, last);
        link(last, first);
        link(first, last_next);
    } else {
        link(first_prev, last);
        link(last, first_next);

        link(last_prev, first);
        link(first, last_next);
    }
    if (k == 1)
        swap(head, tail);
}