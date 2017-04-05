/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// first, inOrderTraversal to get a vector with ascending elements, then access each element in the list one by one
class BSTIterator {
public:
    BSTIterator(TreeNode *root):idx(0) { // ------------
        inOrderTraversal(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return idx!=list_tree.size();  // -----------------
    }

    /** @return the next smallest number */
    int next() {
        return list_tree[idx++];  // -------------------
    }
    
    void inOrderTraversal(TreeNode *node) {
        if (!node) return;
        inOrderTraversal(node->left);
        list_tree.push_back(node->val);
        inOrderTraversal(node->right);
    }
private:
    vector<int> list_tree;
    int idx;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

// use the idea of inorder traversal, maintain a stack
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s_in.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = s_in.top();
        s_in.pop();
        pushAll(tmp->right);
        return tmp->val;
    }
    
    void pushAll(TreeNode *node) {
        while (node) {
            s_in.push(node);
            node = node->left;
        }
    }
private:
    stack<TreeNode *> s_in;
};