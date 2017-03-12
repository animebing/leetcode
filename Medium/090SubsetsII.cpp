// similar to subset I, but here I need to sort first, then a number is not visited for the first time, it will be ignored
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> com;
        helper(nums, 0, com, res);
        return res;
    }
private:
    void helper(vector<int> &nums, int start, vector<int> &com, vector<vector<int>> &res) {
        res.push_back(com);
        for (int i = start; i < nums.size(); i++) {
            if (i==start || nums[i]!=nums[i-1]) {
                com.push_back(nums[i]);
                helper(nums, i+1, com, res);
                com.pop_back();
            }
        }
    }
};


// same idea as above, but use map to record the number of occurrence of each element, when the remaining number of occurrence
// one element is 0, then visit another element, use map can avoid to make duplicate subsets
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int a:nums) cnt[a]++;
        vector<vector<int>> res;
        vector<int> com;
        helper(cnt, cnt.begin(), com, res);
        return res;
    }
private:
    void helper(unordered_map<int, int> &cnt, unordered_map<int, int>::iterator start, vector<int> &com, vector<vector<int>> &res) {
        res.push_back(com);
        for (auto iter = start; iter != cnt.end(); iter++) {
            if (iter->second) {
                com.push_back(iter->first);
                iter->second--;
                helper(cnt, iter, com, res);
                iter->second++;
                com.pop_back();
            }
        }
    }
};

// based on the solution of mathsam, https://discuss.leetcode.com/topic/4661/c-solution-and-explanation
// the author sort the nums first, then get the number of occurrence of each element in the for loop
// similar to the dp in subset II, but here I will compute the number of occurrence of each elements, then for each subset 
// before, then can add diffrent number of current element to get the new subset
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int a:nums) cnt[a]++;
        vector<vector<int>> res;
        res.push_back(vector<int>());
        for (auto iter = cnt.begin(); iter != cnt.end(); iter++) {
            int n = res.size();
            for (int i = 0; i < n; i++) {
                vector<int> tmp(res[i]);
                for (int j = 0; j < iter->second; j++) {
                    tmp.push_back(iter->first);
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};