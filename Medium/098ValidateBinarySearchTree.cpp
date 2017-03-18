/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// if the inorder traversal result of the tree is increasing < == > the tree is BST
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> visit;
        inorder(root, visit);
        if (visit.size() == 1) return true;
        for (int i = 0; i < visit.size()-1; i++) {
            if (visit[i] >= visit[i+1]) return false;
        }
        return true;
    }
private:
    void inorder(TreeNode *root, vector<int> &visit) {
        if (!root) return;
        inorder(root->left, visit);
        visit.push_back(root->val);
        inorder(root->right, visit);
    }
};



// based on the solution of jaewoo, https://discuss.leetcode.com/topic/4659/c-in-order-traversal-and-please-do-not-rely-on-buggy-int_max-int_min-solutions-any-more/11
// use min_node and max_node to represent should-be min and max node, then the value of each node should be less than max
// greater than min
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return helper(root, NULL, NULL);
    }
private:
    bool helper(TreeNode *node, TreeNode *min_node, TreeNode *max_node) {
        if (!node) return true;
        if ((min_node&&node->val<=min_node->val) || (max_node&&node->val>=max_node->val)) return false;
        return helper(node->left, min_node, node) && helper(node->right, node, max_node);  // left node, max is current node
    }                                                                                      // right node, min is current node
};


// inorder traversal, then the value of current node should be greater than the value of previous node
// if so, update the previous node
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *pre_node = NULL;
        return helper(root, pre_node);
    }
private:
    bool helper(TreeNode *node, TreeNode* &pre_node) {   // here reference to pre_node to track this node
        if (!node) return true;
        if (!helper(node->left, pre_node)) return false;
        if (pre_node && node->val<=pre_node->val) return false;
        pre_node = node;
        if (!helper(node->right, pre_node)) return false;
        return true;
    }
};