/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// use queue no matter shape of the tree
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeLinkNode *tmp = q.front();
                q.pop();
                if (i == n-1) tmp->next = NULL;
                else tmp->next = q.front();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
    }
};


// based on the solution of flashstone and reeclapple, https://discuss.leetcode.com/topic/1106/o-1-space-o-n-complexity-iterative-solution/6
// BFS traversal
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *head = root; // head is first node in current level
        while (head) {
            TreeLinkNode *cur = head, *prev = NULL;     // cur is the node in current level, prev is the previous node in next level
            head = NULL;
            while (cur) {
                if (cur->left) {
                    if (prev) prev->next = cur->left;
                    else head = cur->left;
                    prev = cur->left;
                }
                if (cur->right) {
                    if (prev) prev->next = cur->right;
                    else head = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            }
        }
    }
};