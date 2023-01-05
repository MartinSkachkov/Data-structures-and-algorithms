#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *sortedListToBST(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *slow = head, *fast = head, *temp = head;
    while (fast && fast->next) {
        temp = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    temp->next = nullptr;

    TreeNode *result = new TreeNode(slow->val);
    result->left = sortedListToBST(head);
    result->right = sortedListToBST(slow->next);

    return result;
}

void inorder(TreeNode *t) {
    if (t == nullptr) {
        return;
    }

    inorder(t->left);
    cout << t->val << ' ';
    inorder(t->right);
}

void freeList(ListNode *l) {
    while (l != nullptr) {
        ListNode *toDel = l;
        l = l->next;
        delete toDel;
    }
}

int main() {
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    inorder(sortedListToBST(head));

    return 0;
}