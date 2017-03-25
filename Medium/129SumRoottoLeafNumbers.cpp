/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// naive BFS, every node I am going to access is not NULL, pre_sum is the number represented by previous node
// so the value of current number is pre_num*10 + node->val
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        helper(root, 0, res);
        return res;
    }
private:
    void helper(TreeNode *node, int pre_sum, int &total_sum) {
        pre_sum = pre_sum*10+node->val;
        if (!node->left && !node->right) {
            total_sum += pre_sum;
            return;
        }
        if (node->left) helper(node->left, pre_sum, total_sum);
        if (node->right) helper(node->right, pre_sum, total_sum);
    }
};