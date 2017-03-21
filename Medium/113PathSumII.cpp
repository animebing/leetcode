/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// the solution can reach the goal, but I feel it is not the best
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> com;
        helper(res, com, root, sum);
        return res;
    }
private:
    void helper(vector<vector<int>> &res, vector<int> com, TreeNode *node, int left) {
        if (!node) return;
        com.push_back(node->val);
        if (left-node->val==0 && !node->left && !node->right) res.push_back(com);   // a path from root to leaf
        helper(res, com, node->left, left-node->val);
        helper(res, com, node->right, left-node->val);
    }
};


// some optimization based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/18454/12ms-11-lines-c-solution
// here for variable com, using reference and first check whether the node is leaf
// when you use reference to com, you have to pop back the last element at last
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<int> com;
        helper(res, com, root, sum);
        return res;
    }
private:
    void helper(vector<vector<int>> &res, vector<int> &com, TreeNode *node, int left) {
        if (!node) return;
        com.push_back(node->val);
        if (!node->left && !node->right && left==node->val) res.push_back(com);
        helper(res, com, node->left, left-node->val);
        helper(res, com, node->right, left-node->val);
        com.pop_back();
    }
};