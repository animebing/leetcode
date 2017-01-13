/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// based on the solution of jaewoo 
// only when the node is a leaf, then there will be a path
void pathHelper(vector<string> &paths, TreeNode *node, string str){
    if (!node->left && !node->right) {
        paths.push_back(str);
        return;
    }
    if (node->left) pathHelper(paths, node->left, str+"->"+to_string(node->left->val));
    if (node->right) pathHelper(paths, node->right, str+"->"+to_string(node->right->val));
}
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) return paths;
        pathHelper(paths, root, to_string(root->val));
        return paths;
    }
};


// based on the solution of zhukov
// seems more straight forward
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) return paths;
        
        vector<string> left_paths = binaryTreePaths(root->left);
        for (auto path:left_paths)
            paths.push_back(to_string(root->val)+"->"+path);
        
        vector<string> right_paths = binaryTreePaths(root->right);
        for (auto path:right_paths)
            paths.push_back(to_string(root->val)+"->"+path);
        
        if (paths.empty()) paths.push_back(to_string(root->val));
        return paths;
    }
};

// no iterative method here