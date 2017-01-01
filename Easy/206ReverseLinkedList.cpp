/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// reverse one by one, i need record pre, current and next, that is prev_1, prev_2, and tmp in my program
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *prev_1 = NULL, *prev_2 = head, *tmp = head->next;
        while(1) {
            prev_2->next = prev_1;
            prev_1 = prev_2;
            prev_2 = tmp;
            if (!prev_2) break;
            tmp = prev_2->next;
        }
        return prev_1;
    }
};

// based on solution of jianchao.li.fighter
// tha same idea as above, but much conciser
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        while (head){
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

// based on the solution of jianchao.li.fighter and redace85 
// recursion version, reverse head->next first, return node, then deal with head

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};