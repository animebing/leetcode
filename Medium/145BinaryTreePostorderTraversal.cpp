/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// naive recursion solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        helper(root, res);
        return res;
    }
private:
    void helper(TreeNode *node, vector<int> &res) {
        if (!node) return;
        helper(node->left, res);
        helper(node->right, res);
        res.push_back(node->val);
    }
};


// stack iteration solution, similiar to inorder traversal, but for a node we get from stack, we need to check 
// whether its right node has beed visited, if not, visit its right node
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *cur = root, *last = NULL;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                TreeNode *peek = s.top();
                if (!peek->right || peek->right==last) {
                    res.push_back(peek->val);
                    last = peek;
                    s.pop();
                } else cur = peek->right;
            }
        }
        return res;
    }
};

// same as above
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *cur = root, *last = NULL;
        while (true) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            if (s.empty()) break;
            TreeNode *peek = s.top();
            if (!peek->right || peek->right==last) {
                res.push_back(peek->val);
                last = peek;
                s.pop();
            } else cur = peek->right;
        }
        return res;
    }
};

// https://discuss.leetcode.com/topic/14473/0-ms-clear-c-solutions-iterative-recursive-morris-traversal-3-different-solutions/2
// above link has the Morris solution, but it is complex, so I leave it there now