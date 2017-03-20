/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// based on the solution of zxyperfect, Sharing my straightforward recursive solution
// the left most element in preorder is the root node, the  find its pos in inorder traversal, we can find the elements of
// left and right subtree, the number of elements in left and right subtree
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
private:
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int ps, int pe, int is, int ie) {
        if (ps > pe)  return NULL; // the ancestor node is a leaf node
        TreeNode *node = new TreeNode(preorder[ps]);
        int pos = 0;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == node->val) {
                pos = i;
                break;
            }
        }
        node->left = helper(preorder, inorder, ps+1, ps+pos-is, is, pos-1);  // the preorder and inorder result of left subtree
        node->right = helper(preorder, inorder, ps+pos-is+1, pe, pos+1, ie); // the preorder and inorder result of right subtree
        return node;
    }
};



// there is an iterative version, but I can't understand it
// https://discuss.leetcode.com/topic/795/the-iterative-solution-is-easier-than-you-think