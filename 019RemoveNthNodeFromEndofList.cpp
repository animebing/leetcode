/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 1 find the length m of the linked list 
// 2 remove the m-n of the list
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *tmp = head;
        while (tmp != NULL){
             tmp = tmp->next;
             cnt++;   
        }
        int idx = cnt-n;
        if (idx == 0){
            tmp = head->next;
            delete head;
            return tmp;
        }
        ListNode *prev;
        tmp = head;
        for (int i = 0; i < idx; i++){
            prev = tmp;
            tmp = tmp->next;
        } 
        prev->next = tmp->next;
        delete tmp;
        return head;
    }
};

// 1 find the nth node in the list
// 2 go on to find the nth node from the end until the list is over
// 3 use the head node to make it easy to understand
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        ListNode *dummy = new ListNode(0);
        ListNode *s = dummy, *t = dummy;
        dummy->next = head;
        while (t->next){
            if (n-- <= 0) s = s->next;
            t = t->next;
        }
        ListNode *tmp;
        if (s == dummy){
            tmp = head;
            head = head->next;
        }else{
            tmp = s->next;
            s->next = s->next->next;
            head = dummy->next;
        }
        
        delete dummy;
        delete tmp;
        return head;
    }
};