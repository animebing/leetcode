// dp[i][j] represents the number of unique paths in (i+1)*(j+1) grids, so dp[i][j] = dp[i-1][j]+dp[i][j-1]
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m==0 || n==0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int tmp = 0;   // dp[i][j] = dp[i][j-1] + dp[i-1][j]; is okay
                tmp += dp[i][j-1] + dp[i-1][j];
                dp[i][j] = tmp;
            }
        }
        return dp[m-1][n-1];
    }
};


// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/15265/0ms-5-lines-dp-solution-in-c-with-explanations
// use two colums to store info we need and update column by column, so space is O(min(m, n))
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m<=0 || n<=0) return 0;
        if (m > n) return uniquePaths(n, m);  // we hope the number of row is less than that of column
        vector<int> prev(m, 1), cur(m, 1);
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++) {
                cur[i] = cur[i-1] + prev[i];
            }
            prev = cur;
        }
        return prev[m-1];
    }
};


// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/15265/0ms-5-lines-dp-solution-in-c-with-explanations
// use two colums to store info we need and update column by column
// because prev[i] is get from cur[i], so just one column is enough, space is O(min(m, n))
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m<=0 || n<=0) return 0;
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++) {
            for (int i = 1; i < m; i++) {
                cur[i] += cur[i-1];
            }
        }
        return cur[m-1];
    }
};