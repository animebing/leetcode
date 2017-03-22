/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
// breadth first search with O(2^d) space, there d is the depth of the tree indexed from 0
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeLinkNode *tmp = q.front();
                q.pop();
                if (i == n-1) tmp->next = NULL;
                else tmp->next = q.front();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
    }
};

// use the parent to decide the children's  next pointer, 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        root->next = NULL;
        TreeLinkNode *parent = root;
        int p_num = 1;
        while (parent->left) {  // parent is not the last level in the tree
            TreeLinkNode *tmp_parent = parent;
            parent = parent->left; // update the first parent in next level
            for (int i = 0; i < p_num; i++) {
                tmp_parent->left->next = tmp_parent->right;
                if (i == p_num-1) tmp_parent->right->next = NULL;  // the last parent whose right child's next pointer is NULL
                else tmp_parent->right->next = tmp_parent->next->left;
                tmp_parent = tmp_parent->next;  // go to the next parent
            }
            p_num *= 2;
        }
    }
}



// optimize my previous code based on the solution of Erudy, https://discuss.leetcode.com/topic/9579/my-simple-non-iterative-c-code-with-o-1-memory
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *parent = root;
        while (parent->left) {
            TreeLinkNode *tmp_parent = parent;
            while (tmp_parent) {  // use tmp_parent is NULL to indicate whether this level is over
                tmp_parent->left->next = tmp_parent->right;
                if (tmp_parent->next) tmp_parent->right->next = tmp_parent->next->left;
                else tmp_parent->right->next = NULL;
                tmp_parent = tmp_parent->next;
            }
            parent = parent->left;
        }
    }
};



// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/18432/24ms-easy-iterative-and-recursive-c-solutions/2
// recursion version of same idea, a little 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) {
            root->left->next = root->right;
            if (root->next) root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};

