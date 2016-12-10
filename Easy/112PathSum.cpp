/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// BFS, i don't need to traverse one level by one level
typedef pair<TreeNode*, int> nodepair;
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        queue<nodepair> q;
        q.push(make_pair(root, sum));
        while (!q.empty()){
            nodepair tmp = q.front();
            q.pop();
            TreeNode *t = tmp.first;
            int rem = tmp.second;
            if (!t->left && !t->right){
                if (t->val == rem)
                    return true;
            }
            if (t->left) q.push(make_pair(t->left, rem-t->val));
            if (t->right) q.push(make_pair(t->right, rem-t->val));
        }
        return false;
    }
};


// Based on the solution of pankit 
// DFS, i know when to stop, but i don't know how to deal with situation next
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        if (root->val==sum && !root->left && !root->right) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};