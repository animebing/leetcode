/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// use queue, then access the back node of the queue, which is the most right node in a certain level of the tree 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<int> res;
        while (!q.empty()) {
            TreeNode *last = q.back(); // ----------------
            res.push_back(last->val);
            int n = q.size();  // ----------- get earlier
            for (int i = 0; i < n; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return res;
    }
};


// based on the solution of zwangbo, https://discuss.leetcode.com/topic/11768/my-simple-accepted-solution-java
// depth first search, access right node first, the left node, compare current depth(indexed from 0) with res.size() to 
// determine whether to add the value of the node to res.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        helper(root, res, 0);
        return res;
    }
private:
    void helper(TreeNode *node, vector<int> &res, int depth) {
        if (!node) return;
        if (depth == res.size()) res.push_back(node->val);
        helper(node->right, res, depth+1);
        helper(node->left, res, depth+1);
    }
};