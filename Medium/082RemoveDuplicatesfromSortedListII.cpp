/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// based on the solution of RainbowSecret, https://discuss.leetcode.com/topic/33180/recommend-for-beginners-c-implementation-with-detailed-explaination
// just bypass duplicate elements, don't remove them exactly
// I have the same idea, but I don't know how to implement it, aaaaaaaaaaaaaaaaaa
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *cur = head, *next = head->next;
        bool flag = false;
        while (next) {  // -----------------------
            if (next->val == cur->val) {
                flag = true;
                next = next->next;
            }else {
                if (flag) {  // ---------------------------------
                    prev->next = next;
                    cur = next;
                    next = next->next;
                } else {
                    prev = prev->next;
                    cur = cur->next;
                    next = next->next;
                }
                flag = false;
            }
        }
        if (flag) prev->next = next;  // duplicate elements is at the end of list
        return dummy->next;
    }
};


// based on the solution of liismn, https://discuss.leetcode.com/topic/33180/recommend-for-beginners-c-implementation-with-detailed-explaination/2
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *cur = head;
        while (cur && cur->next) {  // double checking
            while (cur->next && cur->val==cur->next->val) cur = cur->next;  
            if (prev->next == cur) {  // there is no dupliate
                prev = cur;
                cur = cur->next;
            } else { // there are duplicates
                prev->next = cur->next;
                cur = cur->next;
            }
        }
        return dummy->next;
        
    }
};