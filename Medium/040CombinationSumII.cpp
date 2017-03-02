// elments are not unique and each element can only be used once
// based on the solution of prime_tang, https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> com;
        helper(candidates, target, res, com, 0);
        return res;
    }
private:
    void helper(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &com, int begin) {
        if (target == 0){
            res.push_back(com);
            return;
        }
        for (int i = begin; i<candidates.size() && target>=candidates[i]; i++) {
            if (i==begin || candidates[i]!= candidates[i-1]){  // prune the duplicate elements
                com.push_back(candidates[i]);
                helper(candidates, target-candidates[i], res, com, i+1);  // start from next elements
                com.pop_back();
            }
        }
    }
};