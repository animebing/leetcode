// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/19110/c-recursive-iterative-bit-manipulation-solutions-with-explanations
// backtracking, subset can begin from any position, maybe this can be regarded as a sign for backtracking
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> com;
        helper(nums, 0, com, res);
        return res;
    }
private:
    void helper(vector<int> &nums, int start, vector<int> &com, vector<vector<int>> &res) {
        res.push_back(com);
        for (int i = start; i < nums.size(); i++) {
            com.push_back(nums[i]);
            helper(nums, i+1, com, res);
            com.pop_back();
        }
    }
};

// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/19110/c-recursive-iterative-bit-manipulation-solutions-with-explanations
// iterative, a little like dynamic programming, the subsets of first i-1 numbers is A, then the subsets of first i numbers
// consists of two parts, first part is the subsets of first i-1 numbers, the another part is every subset of first i-1 numbers plus
// the nums[i]
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            int n = res.size();
            for (int j = 0; j < n; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/19110/c-recursive-iterative-bit-manipulation-solutions-with-explanations
// bit manipulation
// a subset can be regarded as a combination of all numbers, which is in or not in it, so there are 2^n subsets
// for the ith number, if the ith bit of the combination is one, the this number is in the combination
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int num_subsets = 1<<nums.size();
        vector<vector<int>> res(num_subsets, vector<int>());
        for (int i = 0 ; i < nums.size(); i++) {
            for (int j = 0; j < num_subsets; j++) {
                if ((j>>i) & 1) res[j].push_back(nums[i]);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int num_subsets = 1<<nums.size();
        vector<vector<int>> res(num_subsets, vector<int>());
        for (int i = 0; i < num_subsets; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if ((i>>j) & 1) res[i].push_back(nums[j]);
            }
        }
        return res;
    }
};