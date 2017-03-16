/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// trivial recursive traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
private:
    void helper(TreeNode *root, vector<int> &res) {
        if (!root) return;
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
};


// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/14475/clear-c-solutions-iterative-recursive-and-morris-traversal-3-different-solutions
// concise and clever iterative solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> to_visit;
        TreeNode *cur = root;
        while (cur || !to_visit.empty()) {  // ----------------------
            if (cur) {
                to_visit.push(cur);  // --------------------------
                cur = cur->left;
            } else {
                TreeNode *tmp = to_visit.top();
                to_visit.pop(); 
                res.push_back(tmp->val);
                cur= tmp->right;
            }
        }
        return res;
    }
};


// based on the solution of qeatzy, https://discuss.leetcode.com/topic/14475/clear-c-solutions-iterative-recursive-and-morris-traversal-3-different-solutions/3
// iterative solution, push all left child to stack, then visit and do again
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> to_visit;
        TreeNode *cur = root;
        while (1){
            while (cur) {
                to_visit.push(cur);
                cur = cur->left;
            } 
            if (to_visit.empty()) break;
            TreeNode *tmp = to_visit.top();
            to_visit.pop();
            res.push_back(tmp->val);
            cur = tmp->right;
        }
        return res;
    }

};


// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/14475/clear-c-solutions-iterative-recursive-and-morris-traversal-3-different-solutions
// Morris traversal, find the predecessor of current node and
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root;
        while (cur) {
            if (!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode *prev = cur->left;  // --- initial predecessor
                while (prev->right && prev->right!=cur) prev = prev->right;  // find the predecessor
                if (!prev->right) {  // find the predecessor
                    prev->right = cur;
                    cur = cur->left;
                } else {  // we should visit the predecessor ----------------------------------------------
                    prev->right = NULL;
                    res.push_back(cur->val);
                    cur =  cur->right;
                }
            }
        }
        return res;
    }

};