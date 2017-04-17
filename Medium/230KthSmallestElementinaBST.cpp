/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// use inorder traversal, then kth element is the kth smallest element
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res;
        int cnt = 0;
        helper(root, res, k, cnt);   
        return res;
    }
private:
    bool helper(TreeNode *node, int &res, int k, int &cnt) {  // cnt must be a reference, so it must be an variable, not a constant
        if (!node) return false;    
        if (helper(node->left, res, k, cnt)) return true;
        cnt++;
        if (cnt == k) {
            res = node->val;
            return true;
        }
        if (helper(node->right, res, k, cnt)) return true;
        return false;
    }
};


// rescursive solution
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        stack<TreeNode *> s;
        TreeNode *node = root;
        while (1) {
            while (node) {
                s.push(node);
                node = node->left;
            }
            TreeNode *tmp = s.top();
            s.pop();
            node = tmp->right;
            cnt++;
            if (cnt == k) return tmp->val;
        }
    }
};

// binary search like partion in quicksort
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int num = countNodes(root->left);
        if (k <= num) return kthSmallest(root->left, k);
        else if (k > num+1) return kthSmallest(root->right, k-1-num);
        return root->val;
    }
private:
    int countNodes(TreeNode *node) {
        if (!node) return 0;
        return 1+countNodes(node->left)+countNodes(node->right);
    } 
};