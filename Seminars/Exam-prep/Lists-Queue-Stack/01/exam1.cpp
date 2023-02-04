#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

void print(ListNode *head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << '\n';
}

void deleteList(ListNode *head) {
    while (head) {
        ListNode *del = head;
        head = head->next;
        delete del;
    }
}

ListNode *reverseList(ListNode *ll) {
    ListNode *next = nullptr;
    ListNode *prev = nullptr;

    while (ll != nullptr) {
        next = ll->next;
        ll->next = prev;
        prev = ll;
        ll = next;
    }

    return prev; // returns a pointer to the reversed ll head
}

ListNode *shuffle(ListNode *head) {
    // empty list
    if (head == nullptr) {
        return nullptr;
    }

    // one element list
    if (head->next == nullptr || head->next->next == nullptr) {
        return head;
    }

    ListNode *slow = head; // mid ptr
    ListNode *fast = head;

    // find the mid node
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *it = slow->next;
    ListNode *newHead = reverseList(it);

    slow->next = nullptr;
    it->next = head;

    return newHead;
}

int main() {
    // ListNode *ll = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *ll = new ListNode(1, new ListNode(2));
    ListNode *shuffled = shuffle(ll);
    print(shuffled);

    deleteList(ll);
    return 0;
}