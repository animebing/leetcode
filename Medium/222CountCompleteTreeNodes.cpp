/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// naive solution, but TLE
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int n = q.size();
            res += n;
            for (int i = 0; i < n; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return res;
    }
};

// based on the solution of victorlee, https://discuss.leetcode.com/topic/15515/easy-short-c-recursive-solution
// easy case is that the tree is perfect binary tree, so we can first check whether the tree is perfect binary tree, if so, we can get number of nodes directly
// if not, we can compute the nodes of left and right subtree recursively
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left_dep = 0, right_dep = 0;
        TreeNode *left = root, *right = root;
        while (left) {
            left_dep++;
            left = left->left;
        }
        while (right) {
            right_dep++;
            right = right->right;
        }
        if (left_dep == right_dep) return pow(2, left_dep)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};


// another solution is https://discuss.leetcode.com/topic/15533/concise-java-solutions-o-log-n-2