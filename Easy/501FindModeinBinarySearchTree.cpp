/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// there is nothing to do with BST, first traverse the BST tree to compute the occurrence of each unique element
// then compare them one by one, if find element with much larger occurences, then clear the vector, push_back 
// the new element
void traverse(TreeNode *root, unordered_map<int, int>& cnt) {
    if (!root) return;
    cnt[root->val]++;
    traverse(root->left, cnt);
    traverse(root->right, cnt);
}
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> cnt;
        traverse(root, cnt);
        vector<int> res;
        int max = 0;
        for (auto each:cnt) {
            if (each.second == max) res.push_back(each.first);
            else if (each.second > max) {
                res.clear();
                res.push_back(each.first);
                max = each.second;
            }
        }
        return res;
    }
};


// i find 2 solutions using in-order traversal, which will get sorted values of BST tree, but it is hard for me to understand, 
// so disregard them
// https://discuss.leetcode.com/topic/77335/proper-o-1-space
// https://discuss.leetcode.com/topic/77372/11-liner-c-o-n-time-o-1-extra-space-in-order-traversal-detailed-explanation