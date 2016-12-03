// Based on the solution of pankit 
// recursion method with a helper function
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool helper(TreeNode *p, TreeNode *q){
    if (!p || !q) return p==q;
    return p->val==q->val && helper(p->left, q->right) && helper(p->right, q->left);
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
};

// Based on the solution of JayfonLin
// iteration with queues(stack is okay), it also can be implemented by one queue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> queue_p, queue_q;
        queue_p.push(root->left);
        queue_q.push(root->right);
        while(!queue_p.empty() && !queue_q.empty()){
            TreeNode *tmp_p = queue_p.front();
            TreeNode *tmp_q = queue_q.front();
            queue_p.pop();
            queue_q.pop();
            
            if (!tmp_p && !tmp_q) continue;
            if (!tmp_p || !tmp_q) return false;
            if (tmp_p->val != tmp_q->val) return false;
            queue_p.push(tmp_p->left);
            queue_q.push(tmp_q->right);
            queue_p.push(tmp_p->right);
            queue_q.push(tmp_q->left);
        }
        return true;
    }
};

// Based on the solution of biwuxia, pair type, make_pair function, and pair.first, pair.second
// using stack not queue
typedef pair<TreeNode*, TreeNode*> nodepair;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        stack<nodepair> stack_pair;
        stack_pair.push(make_pair(root->left, root->right));
        while (!stack_pair.empty()){
            nodepair tmp = stack_pair.top();
            stack_pair.pop();
            TreeNode *p = tmp.first;
            TreeNode *q = tmp.second;
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            stack_pair.push(make_pair(p->left, q->right));
            stack_pair.push(make_pair(p->right, q->left));
        }
        return true;
    }
};


// Based on the solution of Moduli 
// different from above, but it is really an interesting idea
TreeNode* invertTree(TreeNode *p){
    if (!p) return p;
    TreeNode *tmp = p->left;
    p->left = invertTree(p->right);
    p->right = invertTree(tmp);
    return p;
}
bool isSameTree(TreeNode *p, TreeNode *q){
    if (!p || !q) return p==q;
    return p->val==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSameTree(root->left, invertTree(root->right));
    }
};
