/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// first attempt to use dummy node to make it easy to understand
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *tmp;
        while(head!=NULL && head->next!=NULL){
            tmp = head->next->next;
            prev->next = head->next;
            prev->next->next = head;
            head->next = tmp;
            prev = head;
            head = head->next;
        }
        tmp = dummy->next;
        delete dummy;
        return tmp;
    }
};