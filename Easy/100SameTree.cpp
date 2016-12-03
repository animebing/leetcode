// recursion method, really cool
// Based on the solution of satyakam and RainbowSecret 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL ||  q==NULL) return p==q;
        // or 
        // if (!p && !q) return true;
        // if (!p || !q) return false;
        return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// iteration method using stack, depth first, middle, right, left
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL ||  q==NULL) return p==q;
        stack<TreeNode*> stack_p, stack_q;
        stack_p.push(p);
        stack_q.push(q);
        while (!stack_p.empty() && !stack_q.empty()){
            TreeNode *tmp_p = stack_p.top();
            TreeNode *tmp_q = stack_q.top();
            stack_p.pop();
            stack_q.pop();
            if (tmp_p->val != tmp_q->val) return false;
            // middle, right, left
            if (tmp_p->left) stack_p.push(tmp_p->left);
            if (tmp_q->left) stack_q.push(tmp_q->left);
            if (stack_p.size() != stack_q.size()) return false;
            
            if (tmp_p->right) stack_p.push(tmp_p->right);
            if (tmp_q->right) stack_q.push(tmp_q->right);
            if (stack_p.size() != stack_q.size()) return false;
        }
        return true;
    }
};

// iteration method using queue, breadth first
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL ||  q==NULL) return p==q;
        queue<TreeNode*> queue_p, queue_q;
        queue_p.push(p);
        queue_q.push(q);
        while (!queue_p.empty() && !queue_q.empty()){
            TreeNode *tmp_p = queue_p.front();
            TreeNode *tmp_q = queue_q.front();
            queue_p.pop();
            queue_q.pop();
            if (tmp_p->val != tmp_q->val) return false;
            // middle, right, left
            if (tmp_p->left) queue_p.push(tmp_p->left);
            if (tmp_q->left) queue_q.push(tmp_q->left);
            if (queue_p.size() != queue_q.size()) return false;
            
            if (tmp_p->right) queue_p.push(tmp_p->right);
            if (tmp_q->right) queue_q.push(tmp_q->right);
            if (queue_p.size() != queue_q.size()) return false;
        }
        return true;
    }
};