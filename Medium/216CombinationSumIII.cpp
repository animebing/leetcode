// brute force and pruning,find all combinations of k numbers in [1, 9], then test whether the sum is n
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k<=0 || n<=0) return {};
        if (k > 9) return {};
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, tmp, 0, 1, k, n);
        return res;
    }
private:
    void helper(vector<vector<int>> &res, vector<int> &tmp, int tmp_sum, int start, int left, int n) {
        if (left == 0) {
            if (tmp_sum == n) res.push_back(tmp);
            return;
        } else if (tmp_sum >= n) return;   // pruning operation 1
        for (int i = start; i <= 9-left+1; i++) {   // pruning operation 2, i can be 9-left+1 at most
            tmp.push_back(i);
            helper(res, tmp, tmp_sum+i, i+1, left-1, n);
            tmp.pop_back();
        }
    }
};

// almost same idea, but different implementation
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k<=0 || n<=0) return {};
        if (k > 9) return {};
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, tmp, 1, k, n);
        return res;
    }
private:
    void helper(vector<vector<int>> &res, vector<int> &tmp, int start, int k, int n) {
        if (tmp.size() == k) {  // -----------------
            if (n == 0) res.push_back(tmp);  // ---------------------
            return;
        } else if (n <= 0) return;
        for (int i = start; i <= 9; i++) {   // there is no pruning operation
            tmp.push_back(i);
            helper(res, tmp, i+1, k, n-i);
            tmp.pop_back();
        }
    }
};