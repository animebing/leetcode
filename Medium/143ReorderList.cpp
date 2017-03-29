/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// naive solution, find the last node, then insert it to front and update the last node, repeat again and again
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        while (head->next && head->next->next) { // if there is only two node left, it is okay to stop
            ListNode *tmp = head, *next = head->next;
            while (tmp->next->next) tmp = tmp->next;  // find the second last node, because i need to update the last node 
            ListNode *last = tmp->next;
            tmp->next = NULL;
            head->next = last;  // insert the last to the front
            last->next = next;
            head = next;
        }
    }
};


// find the middle node, then separate the list into two parts, then reverse the right part
// then form the new list from these two parts
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *right = slow->next; // ----------------------
        right = reverseList(right); // ------------------------
        slow->next = NULL;
        while (right) {
            ListNode *next_1 = head->next, *next_2 = right->next;
            head->next = right;
            right->next = next_1;
            head = next_1;
            right = next_2;
        }
    }
private:
    ListNode *reverseList(ListNode *head) {
        if (!head) return NULL;
        ListNode *dummy = new ListNode(0), *last = head;
        dummy->next = head;
        while (last->next) {
            ListNode *cur = last->next,  *next= cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            last->next = next;
        }
        
        return dummy->next;
    }
};