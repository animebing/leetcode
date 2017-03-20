/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// almost same as that using preorder and inorder, but here the right most element in postorder is the root element
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return NULL;
        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
private:
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe) {
        if (is > ie) return NULL;  // if (ps > pe) is okay too 
        TreeNode *node = new TreeNode(postorder[pe]);
        int pos;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == node->val){
                pos = i;
                break;
            }
        }
        node->left = helper(inorder, postorder, is, pos-1, ps, ps+pos-is-1);
        node->right = helper(inorder, postorder, pos+1, ie, ps+pos-is, pe-1);
        return node;
    }
};


// the same as above, but use a map to get the index of element in inorder fastly
// but I find if I define map in buildTree function and pass it as an argument in helper function, 
// there will be time limit exceed
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return NULL;
        for (int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
private:
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe) {
        if (ps > pe) return NULL;  // while (is > ie) is wrong
        TreeNode *node = new TreeNode(postorder[pe]);
        int pos = idx[node->val];
        node->left = helper(inorder, postorder, is, pos-1, ps, ps+pos-is-1);
        node->right = helper(inorder, postorder, pos+1, ie, ps+pos-is, pe-1);
        return node;
    }
    unordered_map<int, int> idx;
};