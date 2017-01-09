/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// based on the solution of http://blog.csdn.net/beiyetengqing/article/details/7633651
// first what is binary search tree(BST), the value of all nodes in left tree is smaller than that in root,
// the value of all nodes in right tree is bigger than that in root, and left and right tree are BST too.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return NULL;
        if (max(p->val, q->val) < root->val) return lowestCommonAncestor(root->left, p, q);
        else if (min(p->val, q->val) > root->val) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};


// based on the solution of jianchao.li.fighter
// iterative, not recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return NULL;
        TreeNode *cur = root;
        while (true){
            if (max(p->val, q->val) < cur->val) cur = cur->left;
            else if (min(p->val, q->val) > cur->val) cur = cur->right;
            else return cur;
        }
    }
};