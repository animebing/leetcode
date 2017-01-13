/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// based on the solution of StefanPochmann
// at first, i think it is impossible to delete a node without giving head,
// but this solution makes it by changing the value of the node, then delete another one
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node->next == NULL) return;
        ListNode *next = node->next;
        *node = *(node->next);  // node->val = node->next->val, node->next = node->next->next;
        delete next;
    }
};