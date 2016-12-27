// use dummy node to simplify the process
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *cur = head;
        while(cur){
            if (cur->val == val){
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};


// based on the solutin of renzid, recursive method
// do removing operation to head->next list, then determine whether we need to delete head 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head; 
    }
};


// based on the solution of JWasper 
// determine whether we need to delete head first, then head->next, slower than above solution
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        if (head->val == val){
            ListNode *tmp = head->next;
            delete head;
            return removeElements(tmp, val);
        }
        head->next = removeElements(head->next, val);
        return head;
    }
};