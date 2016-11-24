/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // increasing list, do what we do to the linear list(array)       9 ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL && l2==NULL) return NULL;
        if (l1!=NULL && l2==NULL) return l1;
        if (l1==NULL && l2!=NULL) return l2;
        ListNode *head, *cur;
        if (l1->val < l2->val){
            head = l1;
            cur = l1;
            l1 = l1->next;
        }else{
            head = l2;
            cur = l2;
            l2 = l2->next;
        }
        while(l1!=NULL && l2!=NULL){   // l1 and l2 can't be NULL at the same time
            if (l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 == NULL) cur->next = l2;
        else cur->next = l1;
        return head;
        }
};


// use dummy node to avoid determining where is head of the final list and avoid repeat work like above.    6 ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (l1 && l2){
            if (l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        else cur->next = l2;
        cur = dummy->next;
        delete dummy;
        return cur;
        }
};


// without dummy node using pointer pointing to a pointer     
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, **tail = &head;
        while (l1 && l2){
            ListNode *tmp;
            if (l1->val < l2->val){
                tmp = l1;
                l1 = l1->next;
            }else{
                tmp = l2;
                l2 = l2->next;
            }
            *tail = tmp;
            tail = &(tmp->next);
        }
        *tail = l1 ? l1 : l2;
        return head;
        }
}; 
