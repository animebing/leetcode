/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// for insertion sort, all visited node should be sorted increasingly, in order to insert next node, 
// i need to visit previous node from right to left, so I change the direction of sorted nodes, at last,
// reverse the list
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = head, *cur = head->next;
        head->next = dummy;
        while (cur) {
            ListNode *next = cur->next;
            ListNode *tmp_prev = prev, *prev_next = cur;  // it seems tmp_prev and prev_next are both necessray    
            while (tmp_prev != dummy){
                if (cur->val >= tmp_prev->val) {
                    if (tmp_prev == prev) cur->next = tmp_prev;
                    else {
                        prev_next->next = cur;
                        cur->next = tmp_prev;
                    }
                    break;
                } else {
                    prev_next = tmp_prev;
                    tmp_prev = tmp_prev->next;
                }
            }
            if (tmp_prev == dummy) {
                prev_next->next = cur;
                cur->next = dummy;
                dummy->next = cur;  // in order to make the last node's next be NULL 
            }
            if (tmp_prev == prev) prev = cur;
            cur = next;
        }
        dummy->next->next = NULL;
        return reverseList(prev);
    }
private:
    ListNode *reverseList(ListNode *node) {
        if (!node) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = node;
        ListNode *last = node;
        while (last->next) {
            ListNode *cur = last->next, *next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            last->next = next;
        }
        return dummy->next;
    }
};


// based on the solution of sbvictory, https://discuss.leetcode.com/topic/8570/an-easy-and-clear-way-to-sort-o-1-space
// here the insertion position is searched from left to right, so we need to find the first node whose val is larger than 
// the insertion node, and here prev->next is used to compare, instead of prev, it can simplify the representation
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy, *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            while (prev->next && prev->next->val<=cur->val) {
                prev = prev->next;
            }
            cur->next = prev->next;
            prev->next = cur;
            prev = dummy;
            cur = next;
        }
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};