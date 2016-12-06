/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// get the top-bottom order vector, then reverse it, 6ms
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            vector<int> vec;
            for (int i = 0, n=q.size(); i < n; i++){
                TreeNode *tmp = q.front();
                q.pop();
                vec.push_back(tmp->val);
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            res.push_back(vec);  // res.insert(res.begin(), vec);
        }
        reverse(res.begin(), res.end());  // comment this line for insert operation
        return res;
    }
};


// Based on the solution of phu1ku 
// calculate depth first, then pre-allocate space for vector<vector<int>>,
// then place from the bottom
int maxDepth(TreeNode* root){
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right))+1;
}

void levelOrder(TreeNode* node, vector<vector<int>> &res, int level){
    if (!node) return;
    res[level].push_back(node->val);
    levelOrder(node->left, res, level-1);
    levelOrder(node->right, res, level-1);
}

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        int depth = maxDepth(root);
        vector<vector<int>> res(depth, vector<int>());
        levelOrder(root, res, depth-1);
        return res;
    }
};