#include <iostream>
#include <stack>

void equalize(ListNode *ll) {
    stack<int> tmp;
    ListNode *iter = ll;

    // push every element from each stack to the tmp stack
    while (iter) {
        while (!iter->val.empty()) {
            tmp.push(iter->val.top());
            iter->val.pop();
        }
        iter = iter->next;
    }

    iter = ll;

    while (!tmp.empty()) {
        if (iter == nullptr) {
            iter = ll;
        }

        iter->val.push(tmp.top());
        tmp.pop();
        iter = iter->next;
    }
}