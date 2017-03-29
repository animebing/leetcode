/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// when there is a cycle, i need to find the first node who is the next of another node, then this
// first node is the begining node of the cycle if the cycle exists
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        while (head) {
            existed[head] = true;  // ------------------
            if (head->next) {
                if (existed[head->next]) return head->next;
                else head = head->next;
            } else return NULL;
        }
    }
private:
    unordered_map<ListNode *, bool> existed; // -------------------------
};



// based on the solution of ngcl, https://discuss.leetcode.com/topic/5284/concise-o-n-solution-by-using-c-with-detailed-alogrithm-description
// use slow and fast pointer to check whether there is a cycle
// then begin to move start head(entry) and slow one node by one node, when entry and slow meets each other, 
// then the entry is the begin node of the cycle
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *slow = head, *fast = head, *entry = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};