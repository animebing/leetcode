/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// I am trying to make the tree balanced, 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        int n = 0;
        ListNode *tmp = head;
        while (tmp) {
            n++;
            tmp = tmp->next;
        }
        return helper(head, n);
    }
private:
    TreeNode *helper(ListNode *head, int n) {
        if (n == 0) return NULL;
        if (n == 1) {
            TreeNode *node = new TreeNode(head->val);
            return node;
        }
        int mid = (n-1)/2;  // mid is indexed from 0 
        int i = 0;
        ListNode *m_node = head;
        while (i != mid) {
            m_node = m_node->next;
            i++;
        }
        TreeNode *node = new TreeNode(m_node->val);
        node->left = helper(head, mid);
        node->right = helper(m_node->next, n-mid-1);
        return node;
    }
};

// based on the solution of AllenYick, https://discuss.leetcode.com/topic/6444/my-accepted-c-solution
// concise solution using tail node, here tail node is excluded 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        return helper(head, NULL);
    }
private:
    TreeNode *helper(ListNode *head, ListNode *tail) {
        if (head == tail) return NULL; // there is no elments
        if (head->next == tail) {        // this if is unnecessary, but can make the program more readable
            TreeNode *node = new TreeNode(head->val);
            return node;
        }
        ListNode *mid = head, *tmp = head;   
        while (tmp!=tail && tmp->next!=tail) {   // so clever here to use slow and fast pointer to find the middle node
            mid = mid->next;
            tmp = tmp->next->next;
        }
        TreeNode *node = new TreeNode(mid->val);
        node->left =helper(head, mid);
        node->right = helper(mid->next, tail);
        return node;
    }
};