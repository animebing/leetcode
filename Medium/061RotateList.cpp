/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// first compute the num of elements in the list, cnt. then k %= cnt to get a simplied k
// then use two pointers to find the last element and the k+1 the from right to left
// here I use a dummy ListNode to simplify the logic
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k == 0) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int cnt = 0;
        ListNode *tmp = dummy;
        while (tmp->next) {
            cnt++;
            tmp = tmp->next;
        }
        if (cnt == 1) return head;
        k %= cnt;
        if (k == 0) return head;
        ListNode *prev = dummy, *prev_k = dummy->next, *last=dummy;
        
        for (int i= 0; i < k; i++) last = last->next;
        while (last->next) {
            last = last->next;
            prev = prev_k;
            prev_k = prev_k->next;
        }
        last->next = dummy->next;
        dummy->next = prev_k;
        prev->next = NULL;
        return dummy->next;
    }
};

// the same as above, I just delete prev_k, which I can get buy prev
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k == 0) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int cnt = 0;
        ListNode *tmp = dummy;
        while (tmp->next) {
            cnt++;
            tmp = tmp->next;
        }
        if (cnt == 1) return head;
        k %= cnt;
        if (k == 0) return head;
        ListNode *prev = dummy, *last=dummy;
        for (int i= 0; i < k; i++) last = last->next;
        while (last->next) {
            last = last->next;
            prev = prev->next;
        }
        last->next = dummy->next;
        dummy->next = prev->next;
        prev->next = NULL;
        return dummy->next;
    }
};
// based on the solution of dong.wang.1694, https://discuss.leetcode.com/topic/14470/my-clean-c-code-quite-standard-find-tail-and-reconnect-the-list
// clever solution, find cnt and tail first, then tail->next = head to make a circle
// later to find the new tail
// but time limit exceeded, I can't understand why
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k==0) return head;
        int cnt = 1;
        ListNode *tail = head;
        while (tail->next) {
            cnt++;
            tail = tail->next;
        }
        if (cnt == 1) return head;
        tail->next = head;  // make a circle
        k %= cnt;
        if (k == 0) return head;   // this sentence can't be executed, i am really confused
        for (int i = 0; i < cnt-k; i++) tail = tail->next;
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};