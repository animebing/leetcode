// just like permutation I, which can avoid duplicates
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return vector<vector<int>> {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        vector<int> tmp(nums);
        while (1) {
            tmp = nextPermutation(tmp);
            if (tmp == nums) break;
            res.push_back(tmp);
        }
        return res;
    }
private:
    vector<int> nextPermutation(vector<int> nums) {
        int k = -1, n = nums.size();
        for (int i = n-1; i >= 1; i--) {
            if (nums[i-1] < nums[i]) {
                k = i-1;
                break;
            }
        }
        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return nums;
        }
        int l = 0;
        for (int i = n-1; i > k; i--) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
        return nums;
    }
};


// based on the solution of dong.wang.1694, https://discuss.leetcode.com/topic/18471/my-c-recursive-dfs-backtracking-solutions
// this method is general for permutation I and II
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> com;
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) cnt[nums[i]]++; // use map to avoid to use duplicate element repeatedly
        helper(nums.size(), res, com, cnt);
        return res;
    }
private:
    void helper(int n, vector<vector<int>> &res, vector<int> &com, unordered_map<int, int> &cnt) {
        if (com.size() == n) {
            res.push_back(com);
            return;
        }
        for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
            if (iter->second) {
                com.push_back(iter->first);
                iter->second--;
                helper(n, res, com, cnt);
                iter->second++;
                com.pop_back();
            }
        }
    }
};


// based on my solution in permutation I
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> com;
        vector<bool> flag(nums.size(), false);
        sort(nums.begin(), nums.end());   // sort is necessary here
        helper(nums, res, com, flag);
        return res;
    }
private:
    void helper(vector<int> nums, vector<vector<int>> &res, vector<int> &com, vector<bool> flag) {
        if (com.size() == nums.size()) {
            res.push_back(com);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (flag[i] == false) {
                if (i>0 && flag[i-1]==false && nums[i]==nums[i-1]) continue; // flag[i-1] is false means that permutation using flag[i-1] has
                com.push_back(nums[i]);                                      // beed done 
                flag[i] = true;
                helper(nums, res,com, flag);
                flag[i] = false;
                com.pop_back();
            }
        }
    }
};