// brute force, but time limit exceeded
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> acc_sum(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            acc_sum[i] = sum;
        }
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == 0) {
                    if (acc_sum[j] > max) max = acc_sum[j];    
                }else {
                    if (acc_sum[j]-acc_sum[i-1] > max) max = acc_sum[j]-acc_sum[i-1];
                }
                
            }
        }
        return max;
    }
};


// based on the solution of FujiwaranoSai, https://discuss.leetcode.com/topic/6413/dp-solution-some-thoughts
// solved by dynamic programming, dp[i] means the max sum of subarray ending with nums[i], so here if dp[i-1] < 0, it should
// be nums[i], otherwise it is dp[i-1]+nums[i], and we need update the final result
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0]  = nums[0];
        int res = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1] > 0 ? dp[i-1]+nums[i] : nums[i];
            res = max(res, dp[i]);
        }
        return res;
    }
};


// based on the solution of lucastan, https://discuss.leetcode.com/topic/3400/simplest-and-fastest-o-n-c-solution
// keeping add an integer to sum until it drops below 0, then reset sum to zero
// sum below 0 will make the following sum much smaller
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0], sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res;
    }
};