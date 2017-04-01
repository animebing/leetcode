/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// merging sort, find the middle element, then sort left, sort right, then merge left and right
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;  // recursion stops
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {   // middle element
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *right = slow->next;
        slow->next = NULL;
        ListNode *left = sortList(head);
        right = sortList(right);
        head = merge(left, right);
        return head;
    }
private:
    ListNode *merge(ListNode *left, ListNode *right) {
        if (!left) return right;
        if (!right) return left;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        while (left && right) {
            if (left->val <= right->val) {
                prev->next = left;
                left = left->next;
            } else {
                prev->next = right;
                right = right->next;
            }
            prev = prev->next;
        }
        if (left) prev->next = left;
        if (right) prev->next = right;
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};