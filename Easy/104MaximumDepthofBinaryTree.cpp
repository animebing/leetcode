/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // traverse the tree until leaf node, then compare depth with the max depth, then update the depth
void traversal(int &res, TreeNode* node, int depth){
    if (!node->left && !node->right){
        if (depth > res) res = depth;
        return;
    } 
    if (node->left) traversal(res, node->left, depth+1);
    if (node->right) traversal(res, node->right, depth+1);
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        traversal(res, root, 1);
        return res;
    }
};


// intuitive method
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int left_d, right_d;  // return 1+max(maxDepth(root->left), maxDepth(root->right));
        left_d = maxDepth(root->left);
        right_d = maxDepth(root->right);
        return left_d > right_d ? left_d+1 : right_d+1;
    }
};

// Based on the solution of makuiyu 
class Solution{
public:
    int maxDepth(TreeNode *root){
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()){
            res++;
            for (int i = 0, n = q.size(); i < n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return res;
    }
}