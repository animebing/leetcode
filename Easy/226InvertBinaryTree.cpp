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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;   // at first, my condition here is if (!root->left && !root->left) there will be runtime error
        TreeNode *tmp = invertTree(root->left);   // i found that if root is NULL, there is no root->left or root->right, so the error occurs
        root->left = invertTree(root->right);
        root->right = tmp;
        return root;
    }
};


// iterative with BFS and queue
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode *f = q.front();
            q.pop();
            swap(f->left, f->right);    // use swa
            if (f->left) q.push(f->left); 
            if (f->right) q.push(f->right);
        }
        return root;
    }
};

// iterative with DFS and stack
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode *f = q.front();
            q.pop();
            swap(f->left, f->right);
            if (f->left) q.push(f->left);
            if (f->right) q.push(f->right);
        }
        return root;
    }
};