/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// find the m_th element and (n+1) element, inverse the element between
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m==n) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head, *tmp_cur;
        bool flag = false;
        int i = 1;
        while (cur) {
            ListNode *tmp = cur; 
            cur = cur->next;  // do this early, or other operation will change the content of cur->next
            if (i == m) {
                tmp_cur = tmp; // we begin to inverse, record the previous element
            } else if (i < m) pre = tmp;
            else {
                tmp->next = tmp_cur;
                tmp_cur = tmp;
                if (i == n) {
                    pre->next->next = cur;
                    pre->next = tmp;
                    break;
                }
            }
            i++;
        }
        return dummy->next;
    }
};


// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/15034/12-lines-4ms-c
// much conciser than mine, 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m==n) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        for (int i = 0; i < m-1; i++) pre = pre->next;
        ListNode *cur = pre->next;
        for (int i = 0; i < n-m; i++) {
            ListNode *move = cur->next;
            cur->next = move->next;
            move->next = pre->next;
            pre->next = move;
        }
        return dummy->next;
    }
};

// modification for my first solution, making it much readable and concise based on the second solution
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next || m==n) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        for (int i = 0; i < m-1; i++) pre = pre->next;
        ListNode *tmp_cur = pre->next;
        ListNode *cur = tmp_cur->next;
        for (int i = 0; i < n-m; i++) {
            ListNode *tmp = cur;
            cur = cur->next;
            tmp->next = tmp_cur;
            tmp_cur = tmp;
        }
        pre->next->next = cur;
        pre->next = tmp_cur;
        return dummy->next;
    }
};