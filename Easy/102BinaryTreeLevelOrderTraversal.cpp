/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// naive idea, use queue to access each elements in each level, use level to identify level
typedef pair<TreeNode*, int> nodePair;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<nodePair> queue_p;
        int level = 0;
        vector<int> vec;
        if (root) queue_p.push(make_pair(root, 0));
        else return result;
        while (!queue_p.empty()){
            nodePair tmp = queue_p.front();
            queue_p.pop();
            if (tmp.second != level){
                cout << tmp.second << endl;
                result.push_back(vec);
                vec.clear();
                level = tmp.second;
            }
            vec.push_back(tmp.first->val);
            if (tmp.first->left) queue_p.push(make_pair(tmp.first->left, level+1));
            if (tmp.first->right) queue_p.push(make_pair(tmp.first->right, level+1));
        }
        result.push_back(vec);
        return result;
    }
};


// Based on the solution of nilath, it is really excellent using DFS to finish BFS work
void buildVector(vector<vector<int>> &result, TreeNode* root, int depth){
    if (!root) return;
    if (result.size() == depth) result.push_back(vector<int>());
    result[depth].push_back(root->val);
    buildVector(result, root->left, depth+1);
    buildVector(result, root->right, depth+1);
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        buildVector(result, root, 0);
        return result;
    }
};



// Based on the solution of kelseyzhou 
// access row by row, at the beginning of the outer loop, queue_p store all elements in one level
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> queue_p;
        queue_p.push(root);
        while (!queue_p.empty()){
            vector<int> vec;
            int len = (int)queue_p.size();
            while (len--){
                TreeNode *tmp = queue_p.front();
                queue_p.pop();
                vec.push_back(tmp->val);
                if (tmp->left) queue_p.push(tmp->left);
                if (tmp->right) queue_p.push(tmp->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};