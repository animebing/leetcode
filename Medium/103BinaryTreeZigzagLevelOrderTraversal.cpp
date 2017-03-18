/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// practice on the paper, use stack to store all elements in one level, then access one by one
// but for adjacent level, the order to add children node is opposite
// we have to use a new stack to store all elements in the next level
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        stack<TreeNode *> zigzag;
        zigzag.push(root);
        bool flip = true;
        while (!zigzag.empty()) {  
            int n = zigzag.size(); // ---------------------------
            vector<int> level;  
            stack<TreeNode *> new_zigzag;  // -----------------------
            for (int i = 0; i < n; i++) {
                TreeNode *tmp = zigzag.top();
                zigzag.pop();
                level.push_back(tmp->val);
                if (flip) {  // left to right
                    if (tmp->left) new_zigzag.push(tmp->left);
                    if (tmp->right) new_zigzag.push(tmp->right);
                } else {  // right to left
                    if (tmp->right) new_zigzag.push(tmp->right);
                    if (tmp->left) new_zigzag.push(tmp->left);
                }
            }
            res.push_back(level);
            flip = !flip;  // change the order
            zigzag = new_zigzag;   // update the stack
        }
        return res;
    }
};

// just use queue, no need to care about the order to add child node
// but to reverse the traversal result of each level according to flip
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode *> zigzag;
        zigzag.push(root);
        bool flip = true;
        while (!zigzag.empty()) {
            int n = zigzag.size();
            vector<int> level;
            while (n-- > 0) {
                TreeNode *tmp = zigzag.front();
                zigzag.pop();
                level.push_back(tmp->val);
                if (tmp->left) zigzag.push(tmp->left);
                if (tmp->right) zigzag.push(tmp->right);
            }
            if (!flip) reverse(level.begin(), level.end());
            res.push_back(level);
            flip = !flip;
        }
        return res;
    }
};