/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Based on the solution of samweiss 
// when the node is height balanced, return depth of the node, otherwise return -1
int depth(TreeNode *node){
    if (!node) return 0;
    // determine whether left tree is height balanced
    int l = depth(node->left);
    if (l == -1) return -1;
    // determine whether right tree is height balanced
    int r = depth(node->right);
    if (r == -1) return -1;
    
    if (abs(l-r)>1) return -1;
    return max(l, r)+1;
    
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) == -1 ? false : true;
    }
};