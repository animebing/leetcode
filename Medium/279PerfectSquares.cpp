// based on the solution of Karci, https://discuss.leetcode.com/topic/26400/an-easy-understanding-dp-solution-in-java
// dp solution, dp[i] represents the number of perfect square for i
// for each i, we can try j from 1 to t with t*t<=i, then get 1+dp[i-j*j]+1 for the number of perfect square, then get the minimum
class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        vector<int> dp(n+1, 0);  // ---------------
        for (int i = 1; i <= n; i++) {
            int res = INT_MAX;
            for (int j = 1; j*j <= i; j++) res = min(res, dp[i-j*j]+1);
            dp[i] = res;
        }
        return dp[n];
    }
};