// based on the solution of Undo and Simpleyyt, https://discuss.leetcode.com/topic/64402/c-5-line-body-code-dfs-solution/7
// sumUp is used to find the number of paths from one node
// pathSum is used to begin from a new node to get the same sum
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return sumUp(root, sum) + pathSum(root->left, sum) + pathSum(root->right,	 sum);
    }
private:
    int sumUp(TreeNode *root, int rem){
        if (!root) return 0;
        // when root->val == rem, it should not stop, we still can find other paths whose sum is 0, which meets the requirement
        return (root->val==rem) + sumUp(root->left, rem-root->val) + sumUp(root->right, rem-root->val);
    }
};


// based on the solution of jordandong, https://discuss.leetcode.com/topic/64438/c-straight-forward-solution
// use flag "used" to indicate whether we can start from a children node
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int res = 0;
        helper(root, res, sum, false);
        return res;
    }
    void helper(TreeNode *root, int& res, int sum, bool used) {
        if (!root) return;
        if (root->val == sum) res++;
        helper(root->left, res, sum-root->val, true);
        helper(root->right, res, sum-root->val, true);
        if (used == false) { // if root is used along one path, we can't jump to its children to begin from sum in order to make path continuous 
            helper(root->left, res, sum, false);
            helper(root->right, res, sum, false);
        }
    }
};

