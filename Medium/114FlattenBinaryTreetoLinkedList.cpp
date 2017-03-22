/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// preorder traversal based on the solution of https://www.jiuzhang.com/solutions/flatten-binary-tree-to-linked-list/
// I have the same idea, but wrong implementation
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *prev = NULL;  // ------------ prev is NULL first
        helper(root, prev);
    }
private:
    void helper(TreeNode *node, TreeNode * &prev) {   // here prev is reference
        if (!node) return;
        if (prev) { // with previous node, then left node is NULL, right node is current node
            prev->left = NULL;
            prev->right = node;
        }
        prev = node;
        TreeNode *right = node->right;  // keep right node because later right node will replaced by other node
        helper(node->left, prev);
        helper(right, prev);
    }
};

// iterative preorder traversal based on the solution of https://www.jiuzhang.com/solutions/flatten-binary-tree-to-linked-list/
// the top element in stack is the next element in preorder traversal
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode *> pre;
        pre.push(root);
        while (!pre.empty()) {
            TreeNode *tmp = pre.top();
            pre.pop();
            if (tmp->right) pre.push(tmp->right);
            if (tmp->left) pre.push(tmp->left);
            tmp->left = NULL;
            if (pre.empty()) tmp->right = NULL;
            else tmp->right = pre.top();
        }
    }
};