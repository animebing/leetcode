/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// breadth first, the first node whose left and right children are null
class Solution {
public:
    int minDepth(TreeNode* root) {
       if (!root) return 0;
       queue<TreeNode*> q;
       q.push(root);
       int idx = 0;
       while (!q.empty()){
           idx++;
           for (int i = 0, n = q.size(); i < n; i++){
               TreeNode *tmp = q.front();
               q.pop();
               if (!tmp->left && !tmp->right) return idx;
               if (tmp->left) q.push(tmp->left);
               if (tmp->right) q.push(tmp->right);
           }
       }
       return -1; // for the compiler thing, the code never runs here, this line refers to the solutio of simkieu 
    }
};


// Based on the solution of a77d4e06 
// Depth first, the tricy thing is how to deal with the situation in which at least one child is null
class Solution {
public:
    int minDepth(TreeNode* root) {
       if (!root) return 0;
       if (root->left && root->right) return min(minDepth(root->left), minDepth(root->right))+1;
       else return max(minDepth(root->left), minDepth(root->right))+1;
    }
};