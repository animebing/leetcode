/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// reverse the whole list to a new one, then compare these two lists
// space O(n), time O(n)
ListNode *inverseList(ListNode *head){
    ListNode *dummy = new ListNode(0);
    while (head){
        ListNode *tmp = dummy->next;
        ListNode *node = new ListNode(head->val);
        dummy->next = node;
        node->next = tmp;
        head = head->next;
    }
    return dummy->next;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //if (!head) return false;
        ListNode *new_head = inverseList(head);
        while (head){
            if (head->val != new_head->val) return false;
            head = head->next;
            new_head = new_head->next;
        }
        return true;
    }
};

// based on the solution of YCG09 and my inverse function above
// reverse the right half of the list, then compare the left half and the right half
// use slow and fast point to find the middle element "slow", then reverse slow->next
ListNode *inverseList(ListNode *head){
    ListNode *dummy = new ListNode(0);
    while (head){
        ListNode *tmp = dummy->next;
        ListNode *next = head->next;
        dummy->next = head;
        head->next = tmp;
        head = next;
    }
    return dummy->next;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = inverseList(slow->next);
        slow = slow->next;
        while (slow){
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};


// based on the solution of YCG09 and his inverse function, which can avoid using dummy node
ListNode *inverseList(ListNode *head){
    ListNode *pre = NULL, *next = NULL;
    while (head){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = inverseList(slow->next);
        slow = slow->next;
        while (slow){
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};