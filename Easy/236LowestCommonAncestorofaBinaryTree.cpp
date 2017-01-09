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
// use covers function to test whether the node is in left tree or right tree
// then the same recursion as BST
bool covers(TreeNode *root, TreeNode *p){
    if (!root) return false;
    if (root == p) return true;
    return covers(root->left, p) || covers(root->right, p);
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (covers(root->left, p) && covers(root->left, q)) return lowestCommonAncestor(root->left, p, q);
        else if (covers(root->right, p) && covers(root->right, q)) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};


// based on the solution of StefanPochmann
// here lowesetCommonAncestor function has two usage, one for check whether p or q in the left tree or right tree
// the other is to return lowest common ancestor
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root==p || root==q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : (!right ? left : root); 
    }
};