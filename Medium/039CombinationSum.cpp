// when i see this problem, i first think of lower_bound, then sort, 2Sum, 3Sum, but I don't know how to deal with many nodes and 
// how to use repeated nodes
// the solution below is using backtracking for multi-nodes tree
// based on the solution of prime_tang, https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> com;
        helper(candidates, target, res, com, 0);
        return res;
    }
private:
    void helper(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &com, int begin) {
        if (target == 0) {
            res.push_back(com);
            return;
        }
        for (int i = begin; i<candidates.size() && target>=candidates[i]; i++) {  // check target
            com.push_back(candidates[i]);
            helper(candidates, target-candidates[i], res, com, i);     // visit i again to use it repeatedly
            com.pop_back();
        }
    }
};

// https://discuss.leetcode.com/topic/29643/c-binary-search-solution-lower_bound-implementation
int lower_bound(vector<int> nums, int target) {
    int low = 0, high = nums.size();  // nums.size()-1 cannot avoid that all elements in nums is less than target
    while (low < high) {   // if low <= high, maybe infinite loop
        int mid = low+(high-low)/2;
        if (target > nums[mid]) low = mid+1;
        else high = mid; 
    }
    return low;
}