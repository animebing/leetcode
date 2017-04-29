// O(n^2) solution, dynamic programming, dp[i] represents the length of longest incresing subsequence ending with nums[i]
// so for nums[i], searching from nums[0] to nums[i-1], if nums[j] < nums[i], then the LIS of nums[j] and nums[i] can 
// form a LIS for nums[i], but there may be many, so I need to find the max one
// at first I think the subsequence must be continuous, that is too easy
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        dp[0] = 1; // ------------------
        int res = 1;
        for (int i = 1; i < n; i++) {
            int tmp = 1;  // ------------------
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) tmp = max(tmp, dp[j]+1);
            }
            dp[i] = tmp;
            res = max(res, tmp);
        }
        return res;
    }
};