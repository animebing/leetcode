/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// in order to make a balanced BST, i choose the middle element as the root node, then build 
// left and right subtree using same way
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return helper(nums, 0, nums.size()-1);
    }
private:
    TreeNode *helper(vector<int> &nums, int start, int end) {
        if (start > end) return NULL;
        int mid = start+(end-start)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = helper(nums, start, mid-1);
        node->right = helper(nums, mid+1, end);
        return node;
    }
};