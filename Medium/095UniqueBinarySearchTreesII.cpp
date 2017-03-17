/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// based on the solution of Jayanta, https://discuss.leetcode.com/topic/3079/a-simple-recursive-solution
// use i as root node, then find the list of left subtree and list of right subtree, one combination of left tree, node, i and right tree 
// will form a BST
// this method is divide and conquer based on the solution of liaison, https://discuss.leetcode.com/topic/8410/divide-and-conquer-f-i-g-i-1-g-n-i
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<TreeNode *> res = helper(1, n);
        return res;
    }
private:
    vector<TreeNode *> helper(int start, int end) {
        vector<TreeNode *> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> left = helper(start, i-1);
            vector<TreeNode *> right = helper(i+1, end);
            for (auto left_n : left) {
                for (auto right_n : right) {
                    TreeNode * root = new TreeNode(i);
                    root->left = left_n;
                    root->right = right_n;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

// based on the solution of Wangxinlei, https://discuss.leetcode.com/topic/6711/share-a-c-dp-solution-with-o-1-space
// get all BST of nth elements based on the result of (n-1)th
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<TreeNode *> res(1, NULL);
        for (int i = 1; i <= n; i++) {
            int n = res.size();
            for (int j = 0; j < n; j++) {
                TreeNode *old_root = res[j];
                TreeNode *new_root = new TreeNode(i); // 1. the nth node is the new root node
                new_root->left = old_root;
                res[j] = new_root;  // update the root
                
                if (old_root) {  // the nth node is not the new root node, then for node with left child, dubbed old_node
                    TreeNode *tmp_node = old_root;   // old_node->right = new_node and new_node->left = old_right
                    while (tmp_node->right) {
                        TreeNode *r_node = tmp_node->right;
                        TreeNode *new_node = new TreeNode(i);
                        tmp_node->right = new_node;
                        new_node->left = r_node;
                        res.push_back(clone(old_root));  // clone all node to form a new tree
                        tmp_node->right = r_node; // recover the original tree because it will be used many times
                        tmp_node = tmp_node->right;
                    } 
                    // we reach the right most node
                    TreeNode *new_node = new TreeNode(i);
                    tmp_node->right = new_node;
                    res.push_back(clone(old_root));
                    tmp_node->right = NULL;
                }
            }
        }
        return res;
    }
private:
    TreeNode * clone(TreeNode *root) {  // clever clone
        if (!root) return NULL;
        TreeNode *new_root = new TreeNode(root->val);
        new_root->left = clone(root->left);
        new_root->right = clone(root->right);
        return new_root;
    }
};