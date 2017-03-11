/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// separate the list to two list, one for element less than x, the other one for elements greater than or equal to x
// here I use two dummy nodes to simplify the thinking.
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode *dummy_1 = new ListNode(0), *dummy_2 = new ListNode(0);
        ListNode *tmp_1 = dummy_1, *tmp_2 = dummy_2;
        while (head) {
            if (head->val < x) {
                tmp_1->next = head;
                tmp_1 = tmp_1->next;
            } else {
                tmp_2->next = head;
                tmp_2 = tmp_2->next;
            }
            head = head->next;
        }
        tmp_1->next = dummy_2->next;
        tmp_2->next = NULL;
        return dummy_1->next;
    }
};