/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Based on the solution of TonyLic 
// if there is a cyble, then a fast pointer will meet the slower one
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *s = head, *f = head;
        while (f && f->next){
            s = s->next;
            f = f->next->next;
            if (s == f) return true;
        }
        return false;
    }
};

// Based on the solution of rich 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *f = head;
        while(head) {
            head = head->next;
            if (f->next && f->next->next) f = f->next->next;
            else return false;
            if (head == f) return true;
        }
        return false;  // only when list is empty
    }
};