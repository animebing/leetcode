// use stack to store nodes
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode *> s;
        s.push(root);
        vector<int> res;
        while (!s.empty()) {
            TreeNode *tmp = s.top();
            s.pop();
            res.push_back(tmp->val);
            if (tmp->right) s.push(tmp->right); // push right node first
            if (tmp->left) s.push(tmp->left);
        }
        return res;
    }
};


// based on the solution of John1993, https://discuss.leetcode.com/topic/21936/4-solutions-in-c 
// use stack, too, but different implementation, visit the element, then push its right node to stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode *> s;
        vector<int> res;
        TreeNode *tmp = root; // ----------------
        while (true) {
            while (tmp) {
                res.push_back(tmp->val);
                if (tmp->right) s.push(tmp->right);  // ------------------
                tmp = tmp->left;
            }
            if (s.empty()) break; 
            tmp = s.top();
            s.pop();
        }
        return res;
    }
};


// based on the solution of John1993, https://discuss.leetcode.com/topic/21936/4-solutions-in-c 
// Morris traversal, almost same as the Morris traversal in inorder traversal, but tiny difference
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        TreeNode *cur = root, *prev;
        vector<int> res;
        while (cur) {
            if (!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right && prev->right!=cur) prev = prev->right;
                if (!prev->right) {
                    res.push_back(cur->val);  // visit first -----------------
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};