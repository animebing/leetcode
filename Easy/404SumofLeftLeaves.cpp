/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// based on the solution of mzchen 
// 1. i want to use recursion, but i don't know what is the return condition 
// 2. i don't know hot to encode the left leaf info
// here use a bool variable to indicate whether the node is a left node
int helper(TreeNode *root, bool is_left) {
    if (!root) return 0;
    if (!root->left && !root->right) return is_left ? root->val : 0;
    return helper(root->left, true) + helper(root->right, false);
}
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return helper(root->left, true) + helper(root->right, false);
    }
};


// based on the solution of luce  
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

        }
    };

// at first, above two solutions confuse me, because in the 1st one, if the node is left leaf, the value of the leaf is returned, 
// but in the 2nd one, not just the value is returned, i still need to add the sumOfLeftLeaves of right tree. 
// later i found that adding the sumOfLeftLeaves of right tree is done in the sumOfLeftLeaves function, not in helper function

// iterative solution
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
            if (!root) return 0;
            int sum = 0;
            queue<pair<TreeNode*, bool> > q;  // make a pair with left or right info
            if (root->left) q.push(make_pair(root->left, true));
            if (root->right) q.push(make_pair(root->right, false));
            while (!q.empty()) {
                pair<TreeNode*, bool> tmp = q.front();
                q.pop();
                if (tmp.second && !tmp.first->left && !tmp.first->right) sum += tmp.first->val;
                if (tmp.first->left) q.push(make_pair(tmp.first->left, true));
                if (tmp.first->right) q.push(make_pair(tmp.first->right, false));
            }
            return sum;
        }
    };